#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int stage[300][300];

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int BFS(pair<int, int> start, pair<int, int> end, int l)
{
    if (start.first == end.first && start.second == end.second)
        return 0;
    queue<pair<int, int> > q;

    q.push(start);

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.first == end.first && cur.second == end.second)
            return stage[cur.first][cur.second];

        for (int i = 0; i < 8; i++)
        {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if (nx < 0 || ny < 0 || nx >= l || ny >= l)
                continue;
            if (stage[nx][ny] != 0)
                continue;

            stage[nx][ny] = stage[cur.first][cur.second] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    return -1;
}

int main()
{
    int cnt;
    int l;
    int x, y;
    int tx, ty;

    cin >> cnt;
    for (int k = 0; k < cnt; k++)
    {
        cin >> l;
        cin >> x >> y;
        cin >> tx >> ty;

        cout << BFS(make_pair(x, y), make_pair(tx, ty), l) << '\n';
        memset(stage, 0, sizeof(stage));
    }
    return 0;
}