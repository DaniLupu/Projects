#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    /** Static Access **/
    char* ptr1;
    int* ptr2;
    long long* ptr3;
    float* ptr4;
    double* ptr5;
    clock_t access_static_start = clock();
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
    clock_t access_static_end = clock();

    double rez = (access_static_end - access_static_start)/(double)CLOCKS_PER_SEC / 1000000;

    FILE* fp = fopen("accessStaticC.txt", "w");
    fprintf(fp, "%.12lf", rez);

    fclose(fp);
}
