#include "iostream"
#include <vector>
using namespace std;
int lengthOfLIS(vector<int> &nums) {
  int dp[2510];
  int ans = 1;
  for (int i = 0; i <= nums.size(); i++) {
    dp[i] = 1;
  }
  for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < i; j++) {
      // dp[i]表示i长的字符串的最长递增序列
      if (nums[i] > nums[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    // cout << dp[i] << " ";
    ans = max(dp[i], ans);
  }
  return ans;
}

int main() {
  int a[9] = {1, 3, 6, 7, 9, 4, 10, 5, 6};
  vector<int> v(a, a + 9);
  lengthOfLIS(v);
  return 0;
}