#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <fstream>
#include <vector>

using namespace std;

#define THREADS_NUM 4

int main(void)
{
    int i;
    omp_set_num_threads(THREADS_NUM);

    ofstream f0;
    f0.open("file_0.txt");
    ofstream f1;
    f1.open("file_1.txt");
    ofstream f2;
    f2.open("file_2.txt");
    ofstream f3;
    f3.open("file_3.txt");

#pragma omp parallel
    for (i = 0; i <= 2; i++)
    {
        int tid = omp_get_thread_num();

        // printf("Thread number: %d     i: %d\n", tid, i);

#pragma omp critical
        switch (tid)
        {
        case 0:
            f0 << " hello from " << tid << " at step:" << i << endl;
            break;
        case 1:
            f1 << " hello from " << tid << " at step:" << i << endl;
            break;
        case 2:
            f2 << " hello from " << tid << " at step:" << i << endl;
            break;
        default:
            f3 << " hello from " << tid << " at step:" << i << endl;
            break;
        }
    }

    f0.close();
    f1.close();
    f2.close();
    f3.close();
}