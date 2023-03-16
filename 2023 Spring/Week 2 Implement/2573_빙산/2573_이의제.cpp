#include <iostream>
#include <tuple>
#include <cstring>
#include <queue>

using namespace std;

int N, M;

int map[300][300];
bool visited[300][300];
vector<tuple<int, int, int>> melt;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(pair<int, int> start)
{
    queue<pair<int, int>> q;

    q.push(start);

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        visited[cur.first][cur.second] = true;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            if (map[nx][ny] != 0 && visited[nx][ny] == false)
                q.push(make_pair(nx, ny));
        }
    }
}

void DFS(pair<int, int> start)
{
    visited[start.first][start.second] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = start.first + dx[i];
        int ny = start.second + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        if (map[nx][ny] != 0 && visited[nx][ny] == false)
            DFS(make_pair(nx, ny));
    }
}

int main()
{
    int year = 0;
    int part = 0;
    bool isEmpty = true;

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
        isEmpty = true;
        part = 0;
        memset(visited, false, sizeof(visited));
        melt.clear();

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (map[i][j] != 0)
                {
                    isEmpty = false;
                    int adjacent = 0;
                    for (int m = 0; m < 4; m++)
                    {
                        int nx = i + dx[m];
                        int ny = j + dy[m];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                            continue;

                        if (map[nx][ny] == 0)
                            adjacent++;
                    }
                    // cout << adjacent << '\n';
                    if (adjacent > 0)
                    {
                        // cout << i << j << adjacent << '\n';
                        melt.push_back(make_tuple(i, j, adjacent));
                    }
                }
            }
        }

        if (isEmpty)
            break;

        for (int i = 0; i < melt.size(); i++)
        {
            int x = get<0>(melt[i]);
            int y = get<1>(melt[i]);

            map[x][y] -= get<2>(melt[i]);
            if (map[x][y] < 0)
                map[x][y] = 0;
            // cout << x << y << map[x][y] << '\n';
        }
        year++;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (map[i][j] != 0 && visited[i][j] == false)
                {
                    DFS(make_pair(i, j));
                    part++;
                }
            }
        }

        if (part >= 2)
            break;
    }

    if (isEmpty) {
        cout << 0;
        return 0;
    }

    cout << year;

    return 0;
}