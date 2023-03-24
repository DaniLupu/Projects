#include <iostream>
#include <Windows.h>

int main()
{
    // Get the current time before migrating the thread
    LARGE_INTEGER startTime;
    QueryPerformanceCounter(&startTime);

    // Get the handle of the current thread
    HANDLE currentThread = GetCurrentThread();

    // Get the number of processors in the system
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    DWORD_PTR numberOfProcessors = sysInfo.dwNumberOfProcessors;

    // Set the processor affinity of the current thread to a different processor
    DWORD_PTR previousAffinity = SetThreadAffinityMask(currentThread, (1 << ((GetCurrentProcessorNumber() + 1) % numberOfProcessors)));

    // Wait for some time
    Sleep(1000);

    // Get the current time after migrating the thread
    LARGE_INTEGER endTime;
    QueryPerformanceCounter(&endTime);

    // Calculate the time difference in seconds
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    double timeDifference = (double)(endTime.QuadPart - startTime.QuadPart) / frequency.QuadPart;

    // Print the execution time of the thread migration
    std::cout << "Execution time of thread migration: " << timeDifference - 1 << " seconds" << std::endl;

    // Clean up
    SetThreadAffinityMask(currentThread, previousAffinity);

    FILE* fp = fopen("threadMigrationCPP.txt", "w");
    fprintf(fp, "%.12lf", timeDifference - 1);

    fclose(fp);

    return 0;
}
