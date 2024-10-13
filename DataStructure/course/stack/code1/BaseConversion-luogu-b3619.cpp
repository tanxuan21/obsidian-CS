#include "iostream"
#include <stack>
#include <string>
using namespace std;
// https://www.luogu.com.cn/problem/P1143
string label = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main() {
  int n, x;
  cin >> n >> x;
  stack<int> ans;
  for (; n / x > 0;) {
    ans.push(n % x);
    n = n / x;
  }
  ans.push(n % x);
  n = n / x;
  // 有些愚蠢。我觉得可以试着写写while
  /**
   * 
   while(n>0){
    ans.push(n%x);
    n/=x;
   }
   * 
   for更多的是对需要index标识循环的封装
   */
  for (; !ans.empty();) {
    cout << label[ans.top()];
    ans.pop();
  }
  return 0;
}