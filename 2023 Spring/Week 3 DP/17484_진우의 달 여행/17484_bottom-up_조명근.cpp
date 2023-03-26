#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 1001;
int N, M;
int map[MAX][MAX];
int dp[MAX][MAX][3];
vector<int> ans;
// 행,열,진행할방향
// 0->왼쪽아래, 1은 아래, 2는 오른쪽아래
void dpset()
{
    memset(dp, INF, sizeof(dp));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[0][i][j] = map[0][i];
        }
    }
    for (int i = 0; i < N; i++)
    {
        dp[i][0][0] = INF;
        dp[i][M - 1][2] = INF;
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
    dpset();
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (j == 0)
            {
                dp[i][j][1] = dp[i - 1][j + 1][0] + map[i][j];
                dp[i][j][2] = min(dp[i - 1][j][1], dp[i - 1][j + 1][0]) + map[i][j];
            }
            else if (j == M - 1)
            {
                dp[i][j][0] = min(dp[i - 1][j - 1][2], dp[i - 1][j][1]) + map[i][j];
                dp[i][j][1] = dp[i - 1][j - 1][2] + map[i][j];
            }
            else
            {
                dp[i][j][0] = min(dp[i - 1][j - 1][2], dp[i - 1][j][1]) + map[i][j];
                dp[i][j][1] = min(dp[i - 1][j - 1][2], dp[i - 1][j + 1][0]) + map[i][j];
                dp[i][j][2] = min(dp[i - 1][j][1], dp[i - 1][j + 1][0]) + map[i][j];
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans.push_back(dp[N - 1][i][j]);
        }
    }
    cout << *min_element(ans.begin(), ans.end());
}