#include <windows.h>
#include <stdio.h>

DWORD WINAPI thread_func(LPVOID lpParam) {
    return 0;
}

int main() {
    HANDLE hThread1, hThread2;
    DWORD dwThreadId1, dwThreadId2;
    LARGE_INTEGER start, end, frequency;
    double execution_time;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    hThread1 = CreateThread(NULL, 0, thread_func, NULL, 0, &dwThreadId1);
    if (hThread1 == NULL) {
        printf("Error creating thread 1\n");
        return 1;
    }

    hThread2 = CreateThread(NULL, 0, thread_func, NULL, 0, &dwThreadId2);
    if (hThread2 == NULL) {
        printf("Error creating thread 2\n");
        return 1;
    }

    WaitForSingleObject(hThread1, INFINITE);
    WaitForSingleObject(hThread2, INFINITE);

    QueryPerformanceCounter(&end);
    execution_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("Execution time of thread context switch: %f seconds\n", execution_time);

    CloseHandle(hThread1);
    CloseHandle(hThread2);

    FILE* fp = fopen("threadContextC.txt", "w");
    fprintf(fp, "%.12lf", execution_time);

    fclose(fp);

    return 0;
}
