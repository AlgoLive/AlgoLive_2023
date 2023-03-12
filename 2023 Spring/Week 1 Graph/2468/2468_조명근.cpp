#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 101;
int N;
int safe;
vector<int> ans;
bool visited[MAX][MAX];
int map[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int a, int b)
{
    visited[a][b] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = a + dx[i];
        int ny = b + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;
        if (!visited[nx][ny])
        {
            visited[nx][ny] = true;
            dfs(nx, ny);
        }
    }
};

void wet(int n)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] <= n)
            {
                visited[i][j] = true;
            }
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < MAX; i++)
    {
        safe = 0;
        memset(visited, false, sizeof(visited));
        wet(i);
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (visited[j][k] == false)
                {
                    dfs(j, k);
                    safe++;
                }
            }
        }
        ans.push_back(safe);
    }
    int max = *max_element(ans.begin(), ans.end());
    cout << max;
}

/*
범위 미스~
*/