#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;
#define MAX 2005
int arr[MAX][MAX]; // 這裏的arr[i][j]表示(0,0)到(i,j)這個子矩陣的所有數和
// 這樣設計可以一步計算得到題目需求
int main() {

  int n, m;
  int q;

  int x, y, a, b;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int num;
      scanf("%d", &num);
      arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + num;
      // out << arr[i][j] << " ";
    }
    // out << std::endl;
  }
  scanf("%d", &q);
  clock_t start = clock();
  for (int i = 0; i < q; i++) {

    scanf("%d %d %d %d", &x, &y, &a, &b);
    x--;
    y--;
    printf("%d\n",
           arr[x + a][y + b] - arr[x][y + b] - arr[x + a][y] + arr[x][y]);
  }
  clock_t end = clock();
  double duration = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "solution_3 花费时常：" << duration << endl;
  return 0;
}