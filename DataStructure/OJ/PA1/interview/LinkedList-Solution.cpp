#include <fstream>
#include <iostream>
using namespace std;
#define MAX 100005
// 環形鏈表插入
struct person {
  int id = 0;
  // 順時針是正方向
  // int next = 0;
  // 逆時針是反方向
  int last = 0;
};
int order[MAX];
person desk[MAX];
int main() {
//   std::ifstream in("./lab1-2.in");
  int n, m;
  cin >> n >> m;
  // 第一個人就坐
  cin >> desk[0].id;
  for (int i = 1; i < n; i++) {
    cin >> desk[i].id;
    int temp = i - 1; // 上一個人的地址
    // 從上一個人開始走過m個人
    for (int j = 1; j < m; j++) {
      temp = desk[temp].last;
    }
    // 在temp那個人的右邊坐下

    desk[i].last = desk[temp].last;
    desk[temp].last = i;

  }
//   std::ofstream out("./lab1-2.out");

  // 準備倒序輸出
  int head = desk[n - 1].last;
  order[0] = desk[head].id;
  for (int i = desk[head].last, j = 1; i != head; i = desk[i].last, j++) {
    order[j] = desk[i].id;
  }
  for (int i = n - 1; i >= 0; i--) {
    cout << order[i] << " ";
  }
  return 0;
}