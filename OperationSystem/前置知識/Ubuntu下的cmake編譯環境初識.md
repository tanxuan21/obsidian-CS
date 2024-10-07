```shell
sudo apt-get install cmake
sudo apt-get install g++
```


一般情況下，直接apt-get的辦法就可以實現cmake安裝。（不記錄不正常的情況）

使用vscode創建一個cpp項目
創建main.cpp文件，書寫c++代碼。
在項目根目錄添加`CmakeLists.txt`文件：

```cmake
cmake_minimum_required(VERSION 3.20)
project(hello)
add_executable(hello main.cpp)
```
分別代表
- 版本號
- 項目名稱
- 編譯產出，編譯的目標文件

運行
```cmake
cmake -B build
```
cmake會生成一系列makefile在build文件夾下。
然後運行
```shell
cmake --build build
```
即可編譯出來可執行文件。運行：
```shell
./build/hello
```
即可運行編譯產出的可執行文件。