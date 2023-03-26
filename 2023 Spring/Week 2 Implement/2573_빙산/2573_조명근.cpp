#include <iostream>
#include <cstring>
const int MAX = 301;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int map[MAX][MAX];
bool visited[MAX][MAX];
int me[MAX][MAX];
int N, M;
int cnt;
using namespace std;

void dfs(int a, int b)
{
    visited[a][b] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx, ny = 0;
        nx = a + dx[i];
        ny = b + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;
        if (map[nx][ny] == 0)
            continue;
        if (!visited[nx][ny])
        {
            visited[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}
void check()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] != 0 && !visited[i][j])
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
}

void search()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
            {
                me[i][j] = 0;
                continue;
            }
            int countwater = 0;
            for (int k = 0; k < 4; k++)
            {
                int nx, ny = 0;
                nx = i + dx[k];
                ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                if (!map[nx][ny])
                {
                    countwater = countwater + 1;
                }
            }
            me[i][j] = countwater;
        }
    }
}

int melt()
{
    search();
    int type = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] != 0)
            {
                type++;
                if (me[i][j] == 0)
                {
                    continue;
                }
                else if (map[i][j] - me[i][j] < 0)
                {
                    map[i][j] = 0;
                }
                else
                {
                    map[i][j] = map[i][j] - me[i][j];
                }
            }
        }
    }
    memset(visited, false, sizeof(visited));
    memset(me, 0, sizeof(me));
    int many = M * N;

    if (type == 0 || type == many)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int time = 0;
    int type = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    while (true)
    {
        check();
        time++;
        type = melt();
        if (cnt != 1 || type == 0)
        {
            break;
        }
        cnt = 0;
    }

    if (type == 0)
    {
        cout << 0;
    }
    else
    {
        cout << time - 1;
    }
}