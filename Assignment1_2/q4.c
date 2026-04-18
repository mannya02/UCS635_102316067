#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;

    #pragma omp parallel reduction(+:sum)
    {
        int id = omp_get_thread_num();
        int square = id * id;
        printf("Thread %d square = %d\n", id, square);
        sum += square;
    }

    printf("Total Sum = %d\n", sum);
    return 0;
}
