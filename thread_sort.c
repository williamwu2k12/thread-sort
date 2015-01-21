#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>
#include <unistd.h>

// gcc-4.9 -fopenmp -O2 -g -std=gnu99 -c -o thread_sort.o thread_sort.c; gcc-4.9 -fopenmp -O2 -g -std=gnu99 thread_sort.c -o thread_sort; ./thread_sort

int * thread_sort(int * data, int size, int range, int accuracy)
{
    int * array = malloc(sizeof(int) * size);
    
    int i = 0;
    omp_set_dynamic(0);
    omp_set_num_threads(size);
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        usleep(accuracy * data[thread_id]);
        #pragma omp critical
        {
            array[i] = data[thread_id];
            i++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return array;
}

int main()
{
    int size = 100;
    int range = 1000;
    int accuracy = 1000;

    int * data = malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++)
    {
        data[i] = rand() % range + 1;
    }

    thread_sort(data, size, range, accuracy);
    return 0;
}
