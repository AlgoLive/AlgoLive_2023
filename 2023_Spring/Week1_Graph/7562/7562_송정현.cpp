#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int T, l, x, y, fx, fy;
int vis[300][300];
int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int bfs(int x, int y, int fx, int fy) {
    if(x == fx && y == fy) {
        return 0;
    }
    queue<pair<int, int>> q;
    vis[x][y] = 0;
    q.push({x,y});

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0; i<8; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
            if(vis[nx][ny] != 0) continue;

            vis[nx][ny] = vis[cur.first][cur.second] + 1;

            if(nx == fx && ny == fy) {
                int cnt = vis[nx][ny];
                return cnt;
            }
            q.push({nx, ny});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> l;
        cin >> x >> y;
        cin >> fx >> fy;

        cout << bfs(x, y, fx, fy) << "\n";
        memset(vis, 0, sizeof(vis));

    }

    return 0;
}
