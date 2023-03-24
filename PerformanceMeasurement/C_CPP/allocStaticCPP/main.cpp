#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

int main()
{
    /** Static Allocation **/
    auto aloc_static_start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < 1000000; i++) {
        char a;
        int b;
        long long c;
        float d;
        double e;
    }
    auto aloc_static_end = chrono::high_resolution_clock::now();

    double aloc_static_time = chrono::duration_cast<chrono::nanoseconds>(aloc_static_end - aloc_static_start).count();
    aloc_static_time *= 1e-9;
    aloc_static_time /= 1000000;

    FILE* fp = fopen("allocStaticCPP.txt", "w");
    fprintf(fp, "%.12lf", aloc_static_time);

    fclose(fp);
}
