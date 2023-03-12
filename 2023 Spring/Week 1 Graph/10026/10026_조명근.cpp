#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 101;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char map[MAX][MAX];
bool visited[MAX][MAX];
int N;
int cnt;

void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx, ny;
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;
        if (map[x][y] == map[nx][ny] && !(visited[nx][ny]))
        {
            dfs(nx, ny);
        }
    }
}

void cmap()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 'R')
            {
                map[i][j] = 'G';
            }
        }
    }
    memset(visited, false, sizeof(visited));
    cnt = 0;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = tmp[j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << " ";
    cmap();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}