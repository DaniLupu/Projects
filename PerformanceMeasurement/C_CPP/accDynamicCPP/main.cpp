#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

int main()
{
    /** Dynamic Access **/
    char* ptr1;
    int* ptr2;
    long long* ptr3;
    float* ptr4;
    double* ptr5;

    auto access_dynamic_start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < 1000000; i++) {
        char* a = (char*)malloc(sizeof(char));
        int* b = (int*)malloc(sizeof(int));
        long long* c = (long long*)malloc(sizeof(long long));
        float* d = (float*)malloc(sizeof(float));
        double* e = (double*)malloc(sizeof(double));

        ptr1 = a;
        ptr2 = b;
        ptr3 = c;
        ptr4 = d;
        ptr5 = e;
    }
    auto access_dynamic_end = chrono::high_resolution_clock::now();

    double access_dynamic_time = chrono::duration_cast<chrono::nanoseconds>(access_dynamic_end - access_dynamic_start).count();
    access_dynamic_time *= 1e-9;
    access_dynamic_time /= 1000000;

    FILE* fp = fopen("accessDynamicCPP.txt", "w");
    fprintf(fp, "%.12lf", access_dynamic_time);

    fclose(fp);
}
