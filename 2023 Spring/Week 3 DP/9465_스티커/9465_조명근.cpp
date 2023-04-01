#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100001
using namespace std;
int dp[2][MAX];
int map[2][MAX];
int T, N;
void printm()
{
    for (int i = 2; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void inputm()
{
    cin >> N;
    memset(map, 0, sizeof(map));
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
}
int main()
{
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        inputm();

        dp[0][0] = map[0][0];
        dp[1][0] = map[1][0];
        dp[0][1] = map[1][0] + map[0][1];
        dp[1][1] = map[0][0] + map[1][1];
        for (int j = 2; j < N; j++)
        {
            dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + map[0][j];

            dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + map[1][j];
        }
        cout << max(dp[0][N - 1], dp[1][N - 1]) << endl;
    }
}
