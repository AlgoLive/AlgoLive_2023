#include <iostream>
#include <cstring>

using namespace std;

int n, cnt;
char map[101][101];
bool visited[101][101];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void DFS(int r, int c){
    visited[r][c] = true;

    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
        if(visited[nr][nc]) continue;
        if(map[r][c] == map[nr][nc]) DFS(nr, nc);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<n; j++){
            map[i][j] = str[j];
        }
    }

    // 일반인의 시야
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                DFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << " ";

    // 색맹 환자를 위한 초기화
    cnt = 0;
    memset(visited, 0, sizeof(visited));

    // 색맹의 시야
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 'G') map[i][j] = 'R';
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                DFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}