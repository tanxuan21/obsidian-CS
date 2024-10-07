#include <fstream>
#include <iostream>
#define MAX 501
using namespace std;

void fn(int n) {
  cout << n << endl;
  fn(n + 1);
}
int main() {
    fn(0);
}