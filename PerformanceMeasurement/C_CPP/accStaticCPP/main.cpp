#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

int main()
{
    /** Static Access **/
    char* ptr1;
    int* ptr2;
    long long* ptr3;
    float* ptr4;
    double* ptr5;
    auto access_static_start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < 1000000; i++) {
        char a;
        int b;
        long long c;
        float d;
        double e;

        ptr1 = &a;
        ptr2 = &b;
        ptr3 = &c;
        ptr4 = &d;
        ptr5 = &e;
    }
    auto access_static_end = chrono::high_resolution_clock::now();

    double access_static_time = chrono::duration_cast<chrono::nanoseconds>(access_static_end - access_static_start).count();
    access_static_time *= 1e-9;
    access_static_time /= 1000000;

    FILE* fp = fopen("accessStaticCPP.txt", "w");
    fprintf(fp, "%.12lf", access_static_time);

    fclose(fp);
}
