#include <stdio.h>
#include <omp.h>

int main() {
    double start, end;

    start = omp_get_wtime();

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            printf("Series of 2:\n");
            for(int i=1;i<=5;i++)
                printf("2^%d = %d\n", i, 1<<i);
        }

        #pragma omp section
        {
            printf("\nSeries of 4:\n");
            for(int i=1;i<=5;i++)
                printf("4^%d = %d\n", i, 1<<(2*i));
        }
    }

    end = omp_get_wtime();

    printf("\nExecution Time: %f\n", end-start);

    return 0;
}
