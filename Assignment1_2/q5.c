#include <stdio.h>
#include <omp.h>

int main() {
    int Aryabhatta = 10;

    #pragma omp parallel private(Aryabhatta)
    {
        Aryabhatta = 10;
        int id = omp_get_thread_num();
        printf("Thread %d result = %d\n", id, id * Aryabhatta);
    }

    return 0;
}
