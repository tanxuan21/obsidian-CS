#include <iostream>
#include <vector>
using namespace std;
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid[0].size();
    int m = grid.size();
    int dp[205][205];
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = grid[0][i] + dp[0][i - 1];
    }
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = grid[i][0] + dp[i - 1][0];
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[m - 1][n - 1];
}
int main()
{
    vector<vector<int>> g = {
        {1, 2, 3}, {4, 5, 6}};
    minPathSum(g);
    int a;
    cin >> a;
    return 0;
}