#include <iostream>
using namespace std;
char _;
int uniquePaths(int m, int n)
{
    int dp[105][105];
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    // for (int i = 1; i < n; i++) {
    //     for (int j = 1; j < m; j++) {
    //         dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    //     }
    // }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[j][i] = dp[j][i - 1] + dp[j - 1][i];
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n - 1][m - 1];
}
int main()
{
    int n, m;
    cin >> m >> n;
    uniquePaths(m, n);
    cin >> n;
    return 0;
}