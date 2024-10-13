# 1.0
# 2.0

$n$个数据需要$10n^2$条指令，标准程序每条指令需要$10^{-8}\sec$，那么标准程序运行这$n$个数据需要$n^2 \times 10^{-7}\sec$，时间上限为$2n^2 \times 10^{-7}\sec$。
## 2A
应当准备$n=\sqrt{(2\times 10^{-7})^{-1}} \approx 2236$的黑盒数据
## 2B
$n$个数据需要$2n\log_{2}^{n} \times 10^{-7}\sec$，时间上限为$4n\log_{2}^{n} \times 10^{-7}\sec$。
于是：$n^n=2^{2.5\times 10^6}$。


# 3
## 3.0
## 3.1
## 3.2
### 3A 
solution_1.cpp
输出的值远大于实际答案值。猜测可能是重复累加了。将14行的`int sum = 0;`移动至查询的for循环内即可解决问题。

solution_2.cpp
根据solution_1.cpp的问题，发现`int sum = 0`没有在查询循环体内部。移入。
运行程序，发现输出负值。由于本次运行测试的样例数据全部为正值，那么，要么是不正确的相减才可能出现负值；要么就是rowsum数组相加不正确，可能漏加了。通过打印rowsum数组，发现rowsum数组符合预期。然后考虑每次查询的计算求合过程，发现y的下标有问题。
修改为如下代码即可解决
```cpp
sum += rowsum[x + j][y + b - 1] - rowsum[x + j][y - 1];
```

### 3B
我使用clang++以及vscode在mac上调试程序。我只需要配置tasks.json时将编译cpp文件的参数加上`-g`即可：
```json
{
	"label": "c/c++ for mac",
	"command": "/usr/bin/clang++",
	"args": [
	"-fcolor-diagnostics",
	"-fansi-escape-codes",
	"-g",
	"${file}",
	"-o",
	"${fileDirname}/${fileBasenameNoExtension}"
	],
}
```

加上`-g`后，编译产出会生成`.DSYM` （debug symbol）文件。这个文件就是维护源代码和二进制可执行文件指令地址的信息。
`launch.json`无需额外配置，直接使用vscode自带的启动模板，选择`c/c++ （lldb）启动`即可。
随后，在代码编辑窗口的行数左边打断点，f5运行即可单步调试。

### 3C
`srand()` 函数用于设置伪随机数生成器的种子（seed）。
而我们使用时间作为种子，那么每次运行的种子都是不一样的，生成的随机数序列也是不一样的。
因此，`srand(time(0));` 的作用是将当前时间作为种子传递给随机数生成器，这样每次程序运行时都能产生不同的随机数序列。如果不这样做，默认情况下，每次运行程序时，伪随机数生成器都会从同一个固定的起点开始，导致生成的随机数序列是相同的。

### 3D

前四行为编译`rand_input.cpp`,`check_input.cpp`,`solution_1.cpp`,`solution_2.cpp`。
然后进入死循环，运行`rand_input`生成随机数据并将其输出结果重定向到`rand.in`文件里。
检查`rand.in`的数据是否合法。
运行`solution_1`,`solution_2`并将其输入重定向为`rand.in`，输入重定向为`1.out`,`2.out`。
使用`diff`指令找两个文件之间的差别。

### 3E

lldb给我如下错误：

```shell
EXC_BAD_ACCESS (code=2, address=0x16f603ff0)
```

是一个地址访问异常的错误。


# 4
### 4A

我设计了一个`dp`矩阵，`dp[i][j]`的含义是从`arr[0][0]`到`arr[i][j]`的子矩阵的每一元的和，也即：
$$dp[i][j] = \sum_{k=0}^{i}\sum_{l=0}^{j}arr[k][l]$$
这样，在读入的时候，`dp[i][j]`可以由`dp[i-1][j]`,`dp[i][j-1]`,`dp[i-1][j-1]`计算得到；
同理，在询问的时候，也可以依据`dp[i-1][j-1]`,`dp[i-1][j]`,`dp[i][j-1]`使用类似的办法一步计算出来。

### 4B

n:100
m:100
q:10000
solution_1 花费时常：0.012617
solution_2 花费时常：0.002685
solution_3 花费时常：0.002011

n:1000
m:1000
q:1000
solution_1 花费时常：0.083707
solution_2花费时常：0.003464
solution_3花费时常：0.000429

n:1999
m:1999
q:1000
solution_1 花费时常：0.326504
solution_2 花费时常：0.012906
solution_3 花费时常：0.000523

n:1999
m:1999
q:10000
solution_1 花费时常：3.21229
solution_2 花费时常：0.033058
solution_3 花费时常：0.003407
### 4C

在n,m,q很大时，solution_3有明显优势。尤其是q很大时，solution_3避免了很多重复的计算
