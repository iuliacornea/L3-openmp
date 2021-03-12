#include <stdio.h>
#include <omp.h>

int main(void)
{
    int i = 10;
    int j = 20;
    int t = 30;

#pragma omp parallel private(i) firstprivate(j)
    {
        printf("thread %d: private(i) i = %d\n", omp_get_thread_num(), i);
        printf("thread %d: firstprivate(j) j = %d\n", omp_get_thread_num(), j);
        printf("thread %d: not specified t = %d\n", omp_get_thread_num(), t);
        i = 1000 + omp_get_thread_num();
        j = 2000 + omp_get_thread_num();
        t = 3000 + omp_get_thread_num();
    }

    printf("i = %d\n", i);
    printf("j = %d\n", j);
    printf("t = %d\n", t);

    return 0;
}