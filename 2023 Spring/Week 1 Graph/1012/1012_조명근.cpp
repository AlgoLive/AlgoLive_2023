#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 51;
int cnt;
int baechu[MAX][MAX];
bool visited[MAX][MAX];
vector<int> ans;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(pair<int, int> start)
{
    int x = start.first;
    int y = start.second;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        pair<int, int> temp = make_pair(nx, ny);
        if (nx < 0 || ny < 0 || nx >= MAX || nx >= MAX)
            continue;
        if (baechu[nx][ny] == 0)
            continue;
        if (!visited[nx][ny])
        {
            visited[nx][ny] = true;
            dfs(temp);
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; i++)
    {
        memset(visited, false, sizeof(visited));
        memset(baechu, 0, sizeof(baechu));
        cnt = 0;
        int M, N, K;
        cin >> M >> N >> K;
        for (int j = 0; j < K; j++)
        {
            int x, y;
            cin >> x >> y;
            baechu[x][y] = 1;
        }
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (!visited[j][k] && baechu[j][k] == 1)
                {
                    visited[j][k] = true;
                    pair<int, int> tmp = make_pair(j, k);
                    dfs(tmp);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}

// 좌표처리 +