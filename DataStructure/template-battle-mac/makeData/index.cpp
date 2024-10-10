#include <iostream>
using namespace std;
int main() {
  srand(time(0));
  string s;
  for (int i = 0; i < 5; i++) {
    char random_char = 'a' + rand() % 26;
    s += random_char;
  }
  cout << s;
  return 0;
}