#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 500   // size (10000 mat lena abhi, system hang ho jayega)

int A[N][N], B[N][N], C[N][N];

int main() {

    // initialize matrices
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            A[i][j] = 1;
            B[i][j] = 1;
        }

    double start, end;

    // 🔴 SERIAL
    start = omp_get_wtime();

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            C[i][j]=0;
            for(int k=0;k<N;k++)
                C[i][j] += A[i][k]*B[k][j];
        }

    end = omp_get_wtime();
    printf("Serial Time: %f\n", end - start);


    // 🟢 PARALLEL STATIC
    start = omp_get_wtime();

    #pragma omp parallel for schedule(static)
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            C[i][j]=0;
            for(int k=0;k<N;k++)
                C[i][j] += A[i][k]*B[k][j];
        }

    end = omp_get_wtime();
    printf("Static Time: %f\n", end - start);


    // 🔵 PARALLEL DYNAMIC
    start = omp_get_wtime();

    #pragma omp parallel for schedule(dynamic)
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            C[i][j]=0;
            for(int k=0;k<N;k++)
                C[i][j] += A[i][k]*B[k][j];
        }

    end = omp_get_wtime();
    printf("Dynamic Time: %f\n", end - start);

    return 0;
}
