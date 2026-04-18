#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int main() {
    FILE *fp;
    fp = fopen("data_local.txt", "w");

    double start = clock();

    for(int i=0; i<N; i++) {
        float num = (float)rand() / RAND_MAX;
        fprintf(fp, "%f\n", num);
    }

    double end = clock();

    fclose(fp);

    double time_taken = (end - start) / CLOCKS_PER_SEC;

    printf("Random numbers generated (Local)\n");
    printf("Execution Time: %f seconds\n", time_taken);

    return 0;
}
