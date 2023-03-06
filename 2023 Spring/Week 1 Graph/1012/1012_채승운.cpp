#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T, m, n, k, cnt;
int map[51][51];
bool visited[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int r, int c){
    queue<pair<int, int> > q;
    q.push(make_pair(r, c));
    visited[r][c] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(map[nx][ny] == 1){
                if(!visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);

    cin >> T;
    for(int a=0; a<T; a++){
        int cnt = 0;
        cin >> m >> n >> k;

        for(int i=0; i<k; i++){
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map[i][j] == 1){
                    if(!visited[i][j]){
                        BFS(i, j);
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << '\n';
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
    }
    return 0;
}