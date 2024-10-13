#include "iostream"
#include <cmath>
using namespace std;
#define MAX 50010
long long arr[MAX]; // 原始數組
int blockID[MAX];   // 是一個映射表，index ->
                    // blockID，後續如l,c就知道了lc所在的blockid。
long long blockSum[MAX]; // 每個分塊的和
int n;
int blockSize; // 塊長

void addC(int l, int r, long long c) {
  if (blockID[l] == blockID[r]) { // 在一個區塊
  }
}
long long query(int l, int r, long long c) {
  long long ans;
  if (blockID[l] == blockID[r]) { // 在一個區塊

  } else {
    for (int i = 0; i < l - r; i++) {
        
    }
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  blockSize = sqrt(n);

  for (int i = 0; i < n; i++) {
    scanf("%lld", arr + i);
    blockID[i] = i / blockSize;
    blockSum[blockID[i]] += arr[i];
  }

  return 0;
}