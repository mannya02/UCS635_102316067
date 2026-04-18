#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for(int i = 1; i <= 20; i++) {
        sum += i;
    }

    printf("Total Sum = %d\n", sum);
    return 0;
}
