#include "../.config/custom_config.h"
#include <cstdlib>
#include <iostream>
using namespace std;
int arr[MAX];
int main() {
  srand(time(0));
  for (int i = 0; i < MAX; i++) {
    arr[i] = rand() % MAX;
    cout << arr[i] << endl;
  }

  return 0;
}