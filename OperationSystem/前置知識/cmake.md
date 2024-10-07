cmake是一門脚本語言。

可以運行任意文件名的但是`.cmake`後綴的cmake脚本

```shell
cmake -P [.cmake文件]
```
# 輸出
```cmake
message(hello,cmake)
message("
打印多行
第二行
")
```
# 變量

初識

```cmake
set(myV 你好，我是自定義變量)
message(${CMAKE_VERSION})
message(${myV})
```

設置多個變量

```cmake
set(List v1;v2)

message(${List})
```

# 環境變量

```cmake
set(ENV{MyC++} "g++")
message($ENV{MyC++})


unset(ENV{MyC++})
message($ENV{MyC++})
```

輸出
第二行報錯了，因爲我們清除了環境變量
```shell
g++
CMake Error at 0.cmake:18 (message):
  message called with incorrect number of arguments

```


# 列表

```cmake
list(LENGTH port len)
list(FIND port p2 index)
list(REMOVE_ITEM port p1)
message(${port})
list(APPEND LISTVALUE a5)
message(${LISTVALUE})
list(INSERT LISTVALUE 3 a4)
message(${LISTVALUE})
message(${len})
message(${index})
```

```shell
a1a2a3
p1p2p3
p2p3
a1a2a3a5
a1a2a3a4a5
3
1
```


條件分支
```cmake
set(Bool TRUE)

if(Bool)

    message(TRUE)

else()

    message(FALSE)

endif()
```

OR EQUAL LESS 等等邏輯布爾運算符

# 循環


# 構建項目

### 簡單構建
```cmake
cmake_minimum_required(VERSION 3.20.0)

project(MySmallProject CXX)

add_executable(MySmallProject main.cpp class/myclass.cpp)
```

直接添加編譯目標文件，這樣做小項目還可以

> 不需要寫頭文件。因爲在源文件裏`include`了.



### 通過字.cmake文件構建

```cmake
set(myclass_sources ./class/myclass.cpp)
```
創建路徑變量，這個cmake文件在子文件夾下與類頭文件源文件在一起

```cmake
cmake_minimum_required(VERSION 3.20.0)
project(MySmallProject CXX)
include(class/class.cmake)
message(${myclass_sources})
add_executable(MySmallProject main.cpp ${myclass_sources})
```

導入make文件，獲取到定義的變量。隨後將這個變量添加到`add_executable`參數内
