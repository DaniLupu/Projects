#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    /** Dynamic Access **/
    char* ptr1;
    int* ptr2;
    long long* ptr3;
    float* ptr4;
    double* ptr5;

    clock_t access_dynamic_start = clock();
    for(int i = 0; i < 1000000; i++) {
        char* a = malloc(sizeof(char));
        int* b = malloc(sizeof(int));
        long long* c = malloc(sizeof(long long));
        float* d = malloc(sizeof(float));
        double* e = malloc(sizeof(double));

        ptr1 = &a;
        ptr2 = &b;
        ptr3 = &c;
        ptr4 = &d;
        ptr5 = &e;
    }
    clock_t access_dynamic_end = clock();

    double rez = (access_dynamic_end - access_dynamic_start)/(double)CLOCKS_PER_SEC / 1000000;

    FILE* fp = fopen("accessDynamicC.txt", "w");
    fprintf(fp, "%.12lf", rez);

    fclose(fp);
}
