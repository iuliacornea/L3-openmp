#include <iostream>

int main()
{
    #pragma omp parallel
    {
        std::cout << "Hello World" << "from CPD" << std::endl;
    }
    return 0;
}