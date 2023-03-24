#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    /** Thread Creation **/
    auto thread_creation_start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < 1000; i++) {
        pthread_t thread_id1;
        pthread_t thread_id2;
        pthread_t thread_id3;
        pthread_t thread_id4;
        pthread_t thread_id5;
        pthread_create(&thread_id1, NULL, NULL, NULL);
        pthread_create(&thread_id2, NULL, NULL, NULL);
        pthread_create(&thread_id3, NULL, NULL, NULL);
        pthread_create(&thread_id4, NULL, NULL, NULL);
        pthread_create(&thread_id5, NULL, NULL, NULL);
    }
    auto thread_creation_end = chrono::high_resolution_clock::now();

    double thread_creation_time = chrono::duration_cast<chrono::nanoseconds>(thread_creation_end - thread_creation_start).count();
    thread_creation_time *= 1e-9;
    thread_creation_time /= 1000;

    FILE* fp = fopen("threadCreateCPP.txt", "w");
    fprintf(fp, "%.12lf", thread_creation_time);

    fclose(fp);
}
