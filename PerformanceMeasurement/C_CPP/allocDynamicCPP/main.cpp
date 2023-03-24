#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

int main()
{
    /** Dynamic Allocation **/
    auto aloc_dynamic_start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < 1000000;i++) {
        char* a = (char*)malloc(sizeof(char));
        int* b = (int*)malloc(sizeof(int));
        long long* c = (long long*)malloc(sizeof(long long));
        float* d = (float*)malloc(sizeof(float));
        double* e = (double*)malloc(sizeof(double));
    }
    auto aloc_dynamic_end = chrono::high_resolution_clock::now();

    double aloc_dynamic_time = chrono::duration_cast<chrono::nanoseconds>(aloc_dynamic_end - aloc_dynamic_start).count();
    aloc_dynamic_time *= 1e-9;
    aloc_dynamic_time /= 1000000;

    FILE* fp = fopen("allocDynamicCPP.txt", "w");
    fprintf(fp, "%.12lf", aloc_dynamic_time);

    fclose(fp);
}
