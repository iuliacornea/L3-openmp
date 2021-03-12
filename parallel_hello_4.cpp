#include <iostream>
#include <cmath>
#include <vector>
#include <omp.h>

#define THREAD_NUM 4

int main( int argc, char* argv[] )
{
	omp_set_num_threads( THREAD_NUM ); // set number of threads in "parallel" blocks

    #pragma omp parallel
    {
        int sleep_time = 5000 * (int) omp_get_thread_num();
        _sleep(sleep_time); // do this to avoid race condition while printing
        std::cout << "Number of available threads: " << omp_get_num_threads() << std::endl;
        // each thread can also get its own number
        std::cout << "Current thread number: " << omp_get_thread_num() << std::endl;
        std::cout << "Hello, World!" << std::endl;
    }
    
    return 0;
}
