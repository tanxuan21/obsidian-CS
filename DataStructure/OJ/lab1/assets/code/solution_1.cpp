#include <cstdio>
#include <ctime>
#include <iostream>
using namespace std::chrono;
using namespace std;
int matrix[2000][2000];

int main() {
  int n, m, q;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &matrix[i][j]);
    }
  }
  scanf("%d", &q);
  clock_t start = clock();
  for (int i = 1; i <= q; ++i) {
    int x, y, a, b;
    int sum = 0;
    scanf("%d %d %d %d", &x, &y, &a, &b);
    for (int j = 0; j < a; ++j) {
      for (int k = 0; k < b; ++k) {
        sum += matrix[x + j][y + k];
      }
    }
    printf("%d\n", sum);
  }
  clock_t end = clock();
  double duration = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "solution_1 花费时常：" << duration << endl;
  return 0;
}