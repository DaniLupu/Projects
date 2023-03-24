#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    /** Dynamic Allocation **/
    clock_t aloc_dynamic_start = clock();
    for(int i = 0; i < 1000000;i++) {
        char* a = malloc(sizeof(char));
        int* b = malloc(sizeof(int));
        long long* c = malloc(sizeof(long long));
        float* d = malloc(sizeof(float));
        double* e = malloc(sizeof(double));
    }
    clock_t aloc_dynamic_end = clock();

    double rez = (aloc_dynamic_end - aloc_dynamic_start)/(double)CLOCKS_PER_SEC / 1000000;

    FILE* fp = fopen("allocDynamicC.txt", "w");
    fprintf(fp, "%.12lf", rez);

    fclose(fp);

    return 0;
}
