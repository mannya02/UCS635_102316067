#include <stdio.h>
#include <omp.h>

int main() {
    int arr[100], sum=0;
    double start, end;

    for(int i=0;i<100;i++)
        arr[i] = 1;

    // WITHOUT SYNCHRONIZATION
    sum = 0;
    start = omp_get_wtime();

    #pragma omp parallel for
    for(int i=0;i<100;i++){
        sum += arr[i];   // race condition
    }

    end = omp_get_wtime();
    printf("Without Sync Sum = %d, Time = %f\n", sum, end-start);


    //  WITH CRITICAL
    sum = 0;
    start = omp_get_wtime();

    #pragma omp parallel for
    for(int i=0;i<100;i++){
        #pragma omp critical
        sum += arr[i];
    }

    end = omp_get_wtime();
    printf("With Critical Sum = %d, Time = %f\n", sum, end-start);


    //  WITH ATOMIC
    sum = 0;
    start = omp_get_wtime();

    #pragma omp parallel for
    for(int i=0;i<100;i++){
        #pragma omp atomic
        sum += arr[i];
    }

    end = omp_get_wtime();
    printf("With Atomic Sum = %d, Time = %f\n", sum, end-start);

    return 0;
}
