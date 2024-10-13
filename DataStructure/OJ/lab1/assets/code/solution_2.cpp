#include "ctime"
#include <cstdio>
#include <iostream>
using namespace std;
int matrix[2000][2000];
int rowsum[2000][2000];

int main() {

  int n, m, q;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &matrix[i][j]);
    }
  }
  clock_t start = clock();
  for (int i = 1; i <= n; ++i) {
    rowsum[i][0] = 0;
    for (int j = 1; j <= m; ++j) {
      rowsum[i][j] = rowsum[i][j - 1] + matrix[i][j];
    }
  }

  scanf("%d", &q);

  for (int i = 1; i <= q; ++i) {
    int sum = 0; // sum移进来
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);
    for (int j = 0; j < a; ++j) {
      // y下标修正
      sum += rowsum[x + j][y + b - 1] - rowsum[x + j][y - 1];
    }
    printf("%d\n", sum);
  }
  clock_t end = clock();
  double duration = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "solution_2 花费时常：" << duration << endl;
  scanf("%d", &q);
  return 0;
}