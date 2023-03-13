#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int n, m, cnt;
int res = 0;
int map[301][301];
int melt[301][301];
bool visited[301][301];
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
            if(!visited[nx][ny] && map[nx][ny] > 0){
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
}

int main(){
    input();
    
    while(1){
        memset(visited, false, sizeof(visited));
        memset(melt, 0, sizeof(melt));
        cnt = 0;

        for(int i=0; i<n; i++){ // BFS가 호출된 횟수 = 빙산 덩어리의 개수
            for(int j=0; j<m; j++){
                if(map[i][j] > 0 && !visited[i][j]){
                    BFS(i, j);
                    cnt++;
                }
            }
        }

        if(cnt >= 2){ // 분리 발생
            cout << res;
            break;
        } else if (cnt == 0){ // 모든 좌표가 0 -> 끝까지 분리되지 않음
            cout << 0;
            break;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map[i][j] > 0){
                    for(int a=0; a<4; a++){
                        int ni = i + dx[a];
                        int nj = j + dy[a];
                        if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                        if(map[ni][nj] <= 0){ // 주변이 0 이하인지 확인 (2인데 3방향이 0이면 -1이므로 음수도 고려해줘야 함)
                            melt[i][j]++;
                        }
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                map[i][j] -= melt[i][j]; // 녹이기
            }
        }
        res++;
    }
    return 0;
}