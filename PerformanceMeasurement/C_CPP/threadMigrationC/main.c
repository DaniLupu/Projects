#include <windows.h>
#include <stdio.h>

DWORD WINAPI thread_func(LPVOID lpParam) {
    //Thread code here
    return 0;
}

int main() {
    HANDLE hThread;
    DWORD dwThreadId;
    LARGE_INTEGER start, end, frequency;
    double execution_time;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    hThread = CreateThread(NULL, 0, thread_func, NULL, 0, &dwThreadId);
    if (hThread == NULL) {
        printf("Error creating thread\n");
        return 1;
    }

    WaitForSingleObject(hThread, INFINITE);

    QueryPerformanceCounter(&end);
    execution_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("Execution time of thread migration: %f seconds\n", execution_time);

    CloseHandle(hThread);

    FILE* fp = fopen("threadMigrationC.txt", "w");
    fprintf(fp, "%.12lf", execution_time);

    fclose(fp);

    return 0;
}
