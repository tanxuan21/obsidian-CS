#include "../.config/custom_config.h"
#include <iostream>
using namespace std;
int arr[MAX];
int main() {
  for (int i = 0; i < MAX; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + MAX);
  for (int i = 0; i < MAX; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}