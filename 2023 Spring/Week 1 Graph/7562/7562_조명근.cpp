#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 301;
bool visited[MAX][MAX];
int chess[MAX][MAX];
int cnt;
vector<int> ans;
int l, sx, sy, endx, endy;
int dy[8] = {-1, -2, -2, -1, 1, 2, 1, 2};
int dx[8] = {-2, -1, 1, 2, -2, -1, 2, 1};

int T;

void bfs(pair<int, int> start)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[sx][sy] = true;
    while (!(q.empty()))
    {
        pair<int, int> cur = q.front();
        q.pop();
        int x, y;
        x = cur.first;
        y = cur.second;
        if (x == endx && y == endy)
        {
            ans.push_back(chess[x][y]);
            continue;
        }
        for (int i = 0; i < 8; i++)
        {
            int nx, ny;
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= l || ny >= l)
                continue;

            if (!visited[nx][ny])
            {
                visited[nx][ny] = true;
                pair<int, int> tmp = make_pair(nx, ny);
                q.push(tmp);
                chess[nx][ny] = chess[x][y] + 1;
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        memset(chess, 0, sizeof(chess));
        memset(visited, false, sizeof(visited));
        cin >> l;
        cin >> sx >> sy;
        pair<int, int> snode = make_pair(sx, sy);
        cin >> endx >> endy;
        bfs(snode);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}
/*
범위를 잘 보고 코딩하자! -> 병신
bfs최단거리는 방문하는 것을 늘려가면서 코딩하는걸로하자!
*/