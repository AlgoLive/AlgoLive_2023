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

int solve(int x, int y, int dir)
{
    if (x == N)
    {
        return 0;
    }

    if (dp[x][y][dir] != INF)
    {
        return dp[x][y][dir];
    }

    // 왼쪽
    if (dir != 0 && y - 1 >= 0)
    {
        dp[x][y][dir] = solve(x + 1, y - 1, 0) + map[x][y];
    }

    // 중앙
    if (dir != 1)
    {
        dp[x][y][dir] = min(dp[x][y][dir], solve(x + 1, y, 1) + map[x][y]);
    }

    // 오른쪽
    if (dir != 2 && y + 1 < M)
    {
        dp[x][y][dir] = min(dp[x][y][dir], solve(x + 1, y + 1, 2) + map[x][y]);
    }

    return dp[x][y][dir];
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
    memset(dp, INF, sizeof(dp));
    for (int i = 0; i < M; i++)
    {
        int tmp = solve(0, i, 3);
        ans.push_back(tmp);
    }
    cout << *min_element(ans.begin(), ans.end());
}