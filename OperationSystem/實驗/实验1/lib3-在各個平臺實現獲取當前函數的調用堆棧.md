


# Ubuntu24.04

必不可少的頭文件庫是execinfo.h。其中最重要的函數：
`int backtrace(void **buffer, int size)`: 获取当前线程的调用堆栈信息，并将其存储在提供的缓冲区中。返回实际获取到的堆栈层数。
`char **backtrace_symbols(void *const *buffer, int size)`: 将调用堆栈地址转换为符号名称（例如函数名和行号）。返回一个指向字符串数组的指针，其中每个字符串表示堆栈中的一层。


print_stack.cpp
```cpp
#include <iostream>
#include <execinfo.h>
  
void print_stackframe()
{
    void *buffer[100];
    int nptrs = backtrace(buffer, 100);
    char **strings = backtrace_symbols(buffer, nptrs);
    if (strings == nullptr)
    {
        perror("backtrace_symbols");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nptrs; i++)
    {
        std::cout << strings[i] << std::endl;
    }
    free(strings);
}

void function3()
{
    print_stackframe();
}

void function2()
{
    function3();
}

void function1()
{
    function2();
}
int main()
{
    function1();
    return 0;
}
```

編譯運行:
```shell
g++ -rdynamic ./print_stack.cpp
./a.out
```

即可出現：
```shell
./a.out(_Z16print_stackframev+0x32) [0x617b7708125b]
./a.out(_Z9function3v+0xd) [0x617b77081337]
./a.out(_Z9function2v+0xd) [0x617b77081347]
./a.out(_Z9function1v+0xd) [0x617b77081357]
./a.out(main+0xd) [0x617b77081367]
/lib/x86_64-linux-gnu/libc.so.6(+0x2a1ca) [0x7b72ddc2a1ca]
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0x8b) [0x7b72ddc2a28b]
./a.out(_start+0x25) [0x617b77081165]
```


[參考鏈接](https://blog.csdn.net/rheostat/article/details/8523598)
