#include "../.config/custom_config.h"
#include <iostream>
using namespace std;
int arr[MAX];

int main() {
  for (int i = 0; i < MAX; i++) {
    cin >> arr[i];
  }
  /**
   * @brief 冒泡排序
   *
   */

  for (int coverCount = 0;;) {
    // 遍历数组，找相邻逆序对
    for (int i = 0; i < MAX - 1; i++) {
      // 找到就交换，并且逆序数加一
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        coverCount++;
      }
    }
    // 直到找不到逆序对，完毕
    if (coverCount == 0) {
      break;
    }
    // 恢复为0
    coverCount = 0;
  }

  for (int i = 0; i < MAX; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}