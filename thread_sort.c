#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>
#include <unistd.h>

// gcc-4.9 -fopenmp -O2 -g -std=gnu99 -c -o thread_sort.o thread_sort.c; gcc-4.9 -fopenmp -O2 -g -std=gnu99 thread_sort.c -o thread_sort; ./thread_sort

void thread_sort(int SIZE, int RANGE)
{
    int * data = malloc(sizeof(int) * SIZE);
    for(int i = 0; i < SIZE; i++)
    {
        data[i] = rand() % RANGE + 1;
    }

    int * array = malloc(sizeof(int) * SIZE);
    
    int i = 0;
    omp_set_dynamic(0);
    omp_set_num_threads(SIZE);
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        usleep(1000 * data[thread_id]);
        #pragma omp critical
        {
            array[i] = data[thread_id];
            i++;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    int SIZE = 100;
    int RANGE = 1000;

    thread_sort(SIZE, RANGE);
    return 0;
}
