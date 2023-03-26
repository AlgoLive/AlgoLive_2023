#include <iostream>
#include <cstring>
const int MAX = 101;
using namespace std;

int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX];
int melt[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cnt;
void printm()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void dfs(int a, int b)
{
    if (cnt != 0)
    {
        map[a][b] = 2;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx, ny;
        nx = a + dx[i];
        ny = b + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;
        if (!visited[nx][ny] && map[nx][ny] == 0)
        {
            visited[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}
void checkair()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j] && map[i][j] == 0)
            {
                visited[i][j] = true;
                dfs(i, j);
                cnt++;
            }
        }
    }
}

void checkmelt()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 1)
            {
                int cntair = 0;
                for (int k = 0; k < 4; k++)
                {
                    int nx, ny;
                    nx = i + dx[k];
                    ny = j + dy[k];
                    if (map[nx][ny] == 0)
                    {
                        cntair++;
                    }
                }
                if (cntair >= 2)
                {
                    melt[i][j] = 1;
                }
            }
        }
    }
}
void meltc()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (melt[i][j] == 1)
            {
                map[i][j] = 0;
            }
        }
    }
}

int checkallmelt()
{
    int check = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] != 0)
            {
                check = 0;
                break;
            }
        }
    }
    return check;
}
void change()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 2)
            {
                map[i][j] = 0;
            }
        }
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

    int t = 0;

    while (true)
    {
        cnt = 0;
        checkair();
        checkmelt();
        meltc();
        change();
        memset(visited, false, sizeof(visited));
        memset(melt, 0, sizeof(melt));
        t++;
        if (checkallmelt())
        {
            break;
        }
    }

    cout << t;
}
