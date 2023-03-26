#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool vis[100][100];
string arr[100];

void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

        if(!vis[nx][ny] && arr[nx][ny] == arr[x][y]) {
            vis[nx][ny] = true;
            dfs(nx, ny);

        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int cnt1 = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!vis[i][j]){
                cnt1++;
                dfs(i, j);
            }
        }
    }
    memset(vis, 0, sizeof (vis));

    int cnt2 = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 'G'){
                arr[i][j] = 'R';
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!vis[i][j]){
                cnt2++;
                dfs(i, j);
            }
        }
    }

    cout << cnt1 << " " << cnt2 << "\n";

    return 0;
}
