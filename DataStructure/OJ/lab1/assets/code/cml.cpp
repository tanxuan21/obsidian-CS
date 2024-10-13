#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    std::cout << "命令行参数数量： " << argc << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << "参数 " << i << ": " << argv[i] << std::endl;
    }
    return 0;
}