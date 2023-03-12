#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int M, N;
const int MAX = 1001;
bool visited[MAX][MAX];
int tom[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;
int print()
{
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (max < tom[i][j])
            {
                max = tom[i][j];
            }
            if (tom[i][j] == 0)
            {
                return -1;
            }
        }
    }
    return max - 1;
}
void bfs()
{
    pair<int, int> start = q.front();
    int sx = start.first;
    int sy = start.second;
    visited[sx][sy] = true;
    while (!(q.empty()))
    {
        pair<int, int> cur = q.front();
        q.pop();
        int nx, ny;
        for (int i = 0; i < 4; i++)
        {
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (!(tom[nx][ny] == 0))
                continue;
            if (!visited[nx][ny])
            {
                tom[nx][ny] = tom[cur.first][cur.second] + 1;
                visited[nx][ny] = true;
                pair<int, int> next = make_pair(nx, ny);
                q.push(next);
            }
        }
    }
}

int main()
{
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> tom[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tom[i][j] == 1)
            {
                q.push(make_pair(i, j));
            }
        }
    }
    bfs();
    cout << print();
    return 0;
}

/*
2차원 배열 입력 , 2차원 배열 설정하는거 생각해보기 가로,세로

*/