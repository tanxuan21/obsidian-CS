操作系统就是一个封装了底层硬件接口的库。是最原始的最轻量的操作系统。

```shell
git checkout ch1
make run LOG=trace
```

>太多的计算机组成原理的内容我暂时不会。我只记录我自己在代码内能理解的东西。

# 实验目标

- 理解LibOS的执行过程
- 会编写/编译/运行裸机程序
- 懂基于裸机程序的函数调用
- 能看懂汇编代码伪代码
- 能看懂内嵌汇编代码
- 初步理解SBI调用

> ABI(application binary interface)
> SBP(supervisor binary interface)

os/main.c
```c

#include "console.h"
#include "defs.h"

extern char s_text[];
extern char e_text[];
extern char s_rodata[];
extern char e_rodata[];
extern char s_data[];
extern char e_data[];
extern char s_bss[];
extern char e_bss[];

  

int threadid()
{
	return 0;
}

  

void clean_bss()
{
	char *p;
	for (p = s_bss; p < e_bss; ++p)
	*p = 0;
}


void main()
{
	clean_bss();
	console_init();
	printf("\n");
	printf("hello wrold!\n");
	errorf("stext: %p", s_text);
	warnf("etext: %p", e_text);
	infof("sroda: %p", s_rodata);
	debugf("eroda: %p", e_rodata);
	debugf("sdata: %p", s_data);
	infof("edata: %p", e_data);
	warnf("sbss : %p", s_bss);
	errorf("ebss : %p", e_bss);
	panic("ALL DONE");
}
```

定义了程序需要的地址段。打印输出到控制台。
```shell
make run LOG=trace
```
```shell
hello wrold!
[ERROR 0]stext: 0x0000000080200000
[WARN 0]etext: 0x0000000080201000
[INFO 0]sroda: 0x0000000080201000
[DEBUG 0]eroda: 0x0000000080202000
[DEBUG 0]sdata: 0x0000000080202000
[INFO 0]edata: 0x0000000080212000
[WARN 0]sbss : 0x0000000080222000
[ERROR 0]ebss : 0x0000000080222000
[PANIC 0] os/main.c:39: ALL DONE
```
可以看到，输出是一一对应的。

# 内存布局
## text
- 执行代码
- 大小确定，只读。
- 也可能包含只读的常量。
## data
- 已经初始化的全局变量。
- 静态内存分配
## bss（block started by symbol）
- 存放全局变量。
- 属于静态内存分配。
## heap
- 动态内存分配
- malloc分配
- free释放

## stack
- 局部变量
- 函数参数，返回值存放到这里。
> 趣闻：栈底是高地址，栈顶是低地址。这根我们的直觉是反的。
- 可以看作是与寄存器交换临时数据的内存区
- 需要理解栈。

## 链接
os/kernel.ld

```asm
OUTPUT_ARCH(riscv)
ENTRY(_entry)
BASE_ADDRESS = 0x80200000;

SECTIONS
{
    . = BASE_ADDRESS;
    skernel = .;
```

等等。虽然不能完全看懂，但是可以知道大意。就是给每个段分配地址的汇编。
`.`是当前地址。汇编就是一条一条地址的操作。
别的有点看不懂了服了


# SBI
os/sbi.c
里面定义了很多sbi
```c
#include "sbi.h"
#include "types.h"

const uint64 SBI_SET_TIMER = 0;
const uint64 SBI_CONSOLE_PUTCHAR = 1;
const uint64 SBI_CONSOLE_GETCHAR = 2;
// ...
```

汇编级别的调用
```c
int inline sbi_call(uint64 which, uint64 arg0, uint64 arg1, uint64 arg2)
{
// ...
}
```

以此函数为界，开启操作系统的编写。

比如向屏幕方一个字符函数：
```c
void console_putchar(int c)
{
	sbi_call(SBI_CONSOLE_PUTCHAR, c, 0, 0);
}
```

> 实现println函数
> 实现panic函数

