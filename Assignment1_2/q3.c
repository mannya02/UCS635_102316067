#include <stdio.h>
#include <omp.h>

int main() {
    char *names[] = {"Maa", "Papa", "Brother", "Sister"};

    #pragma omp parallel num_threads(4)
    {
        int id = omp_get_thread_num();
        printf("Thread %d: %s\n", id, names[id]);
    }
    return 0;
}
