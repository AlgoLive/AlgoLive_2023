#include <iostream>
using namespace std;
#define MAX 201
long long dp[MAX][MAX];
int N, K;

int main()
{
    cin >> N >> K;
    for (int j = 1; j <= K; j++)
    {
        dp[1][j] = j;
    }
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
        }
    }
    cout << dp[N][K];
}