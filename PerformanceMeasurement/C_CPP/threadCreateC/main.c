#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

void threadFunction(){
}

int main()
{
    /** Thread Creation **/
    clock_t thread_create_start = clock();
    for(int i = 0; i < 1000; i++) {
        pthread_t thread_id1;
        pthread_t thread_id2;
        pthread_t thread_id3;
        pthread_t thread_id4;
        pthread_t thread_id5;
        pthread_create(&thread_id1, NULL, threadFunction, NULL);
        pthread_create(&thread_id2, NULL, threadFunction, NULL);
        pthread_create(&thread_id3, NULL, threadFunction, NULL);
        pthread_create(&thread_id4, NULL, threadFunction, NULL);
        pthread_create(&thread_id5, NULL, threadFunction, NULL);
    }
    clock_t thread_create_end = clock();

    double rez = (thread_create_end - thread_create_start)/(double)CLOCKS_PER_SEC / 1000;

    FILE* fp = fopen("threadCreateC.txt", "w");
    fprintf(fp, "%.12lf", rez);

    fclose(fp);
}
