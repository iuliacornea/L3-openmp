1. Download [Visual Studio Code](https://code.visualstudio.com/download) (you can also use notepad++ for writing code or whatever you like, I like this one)
2. Enable the C/C++ extension in VS Code (this will give you some neat autosuggestions)
3. Download [mingw-w64-install.exe](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download) and run it (this will make sure you have a c/c++ compiler and all the libs and dependencies it needs)
4. Add to System environment variables the path (mine was C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin)
5. Download [mingw-get-setup.exe](https://sourceforge.net/projects/mingw/files/latest/download) and run it (You will need to select the developer toolkit and msys base -> Apply changes. This will make sure you can also enalbe the openMP flag)
6. Add to System environment variables the path C:\MinGW\msys\1.0\bin
7. Open VS code and create a new test.cpp file
8. Fill it with 

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

7. From the terminal run ``` g++ test.cpp -fopenmp -o test.exe ``` (or no exe if you're on Linux)
8. The output should be as many **Hello world**s as threads you have
