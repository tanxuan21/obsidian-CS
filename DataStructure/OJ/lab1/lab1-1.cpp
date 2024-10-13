#include <iostream>
#include <fstream>
#define MAX 5010
using namespace std;
int dp[MAX][MAX];
int main()
{
    ifstream in("./lab1-1.in");
    ofstream out("./lab1-1.out");
    int N, M, K;
    string A, B;
    in >> N >> M >> K >> A >> B;

    for (int i = 0; i < N; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j < M; j++)
    {
        dp[j][0] = j;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (A[i - 1] == B[j - 1]) // 相等，忽略。跳過這個字符，AB都縮短，問題規模縮小
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int temp = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            }
            out << dp[i][j] << " ";
        }
        out << endl;
    }

    out << dp[N][M];
    return 0;
}