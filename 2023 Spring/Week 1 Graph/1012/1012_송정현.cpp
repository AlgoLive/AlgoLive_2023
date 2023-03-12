#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


int t, m, n, k, cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1}; //상하좌우
int arr[51][51];
bool vis[51][51];


void bfs(int a, int b) {
    queue<pair<int, int>> q;
    vis[a][b] = true;
    q.push({a,b});

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(arr[nx][ny] && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});

            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for(int v=0; v<t; v++){
        cnt = 0;
        cin >> m >> n >> k;

        for(int i=0; i<k; i++){
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] && !vis[i][j]) {
                        cnt++;
                        bfs(i, j);
                }
            }
        }
        cout << cnt << "\n";
        memset(arr, 0, sizeof(arr));
        memset(vis, false, sizeof(vis));
    }

    return 0;
}
