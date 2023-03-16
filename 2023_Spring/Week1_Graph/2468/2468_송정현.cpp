#include <iostream>
#include <cstring>
using namespace std;

int n, Max = 0, cnt = 0, temp = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int map[101][101];
bool vis[101][101];

void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

        if(!vis[nx][ny]) {
            vis[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(Max < map[i][j]){
                Max = map[i][j];
            }
        }
    }
    for(int i=0; i<Max; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(i >= map[j][k]){
                    vis[j][k] = true;
                }
            }
        }
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(!vis[j][k]) {
                    cnt++;
                    dfs(j, k);
                }
            }
        }
        if(temp < cnt){
            temp = cnt;
        }
        cnt = 0;
        memset(vis, false, sizeof(vis));
    }
    cout << temp;

    return 0;
}