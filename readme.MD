1. Download Visual Studio Code https://code.visualstudio.com/download (you can also use notepad++ for writing code or whatever you like, I like this one)
2. Enable the C/C++ extension in VS Code (this will give you some neat autosuggestions)
3. Download mingw-w64-install.exe and run it (this will make sure you have a c/c++ compiler and all the libs and dependencies it needs)
https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download
4. Download mingw-get-setup.exe and run it (You will need to select the developer toolkit and msys base -> Apply changes. This will make sure you can also enalbe the openMP flag)
https://sourceforge.net/projects/mingw/files/latest/download
5. Open VS code and create a new test.cpp file
6. fill it with 

``` cpp
#include <iostream>

int main()
{
    #pragma omp parallel
    {
        std::cout << "Hello World" << "from CPD" << std::endl;
    }
    return 0;
}
```

7. from the terminal run g++ test.cpp -fopenmp -o test.exe 
(or no exe if you're on Linux)
8. the output should be as many hello worlds as threads you have
