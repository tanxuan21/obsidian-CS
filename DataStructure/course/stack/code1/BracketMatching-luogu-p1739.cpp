#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
  string express;
  cin >> express;
  int count = 0;
  for (int i = 0; i < express.size(); i++) {
    if (express[i] == '(') {
      count++;
    } else if (express[i] == ')') {
      count--;
      if (count < 0) {
        cout << "NO";
        return 0;
      }
    }
  }
  if (count == 0)
    cout << "YES";
  else
    cout << "NO";
}