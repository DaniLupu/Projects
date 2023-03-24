#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <Windows.h>

DWORD WINAPI secondThread(LPVOID lpParameter)
{
    return 0;
}

using namespace std;

int main()
{
    /** Thread Context Switch **/
    LARGE_INTEGER startTime;
    QueryPerformanceCounter(&startTime);

    // Create a second thread
    HANDLE secondThreadHandle = CreateThread(NULL, 0, secondThread, NULL, 0, NULL);

    // Wait for the second thread to complete
    WaitForSingleObject(secondThreadHandle, INFINITE);

    // Get the current time after the second thread has completed
    LARGE_INTEGER endTime;
    QueryPerformanceCounter(&endTime);

    // Calculate the time difference in seconds
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    double timeDifference = (double)(endTime.QuadPart - startTime.QuadPart) / frequency.QuadPart;

    // Print the execution time of the context switch
    std::cout << "Execution time of thread context switch: " << timeDifference << " seconds" << std::endl;

    CloseHandle(secondThreadHandle);

    FILE* fp = fopen("threadContextCPP.txt", "w");
    fprintf(fp, "%.12lf", timeDifference);

    fclose(fp);
}
