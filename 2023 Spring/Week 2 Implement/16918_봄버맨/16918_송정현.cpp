#include <iostream>
#include <queue>
using namespace std;

int r, c, n;
char map[200][200];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

int main(){
    cin >> r >> c >> n;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> map[i][j];
        }
    }
    // n이 짝수일 때 전부 0 출력
    if(n%2 == 0) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << 'O';
            }
            cout << "\n";
        }
        return 0;
    }
    // n이 홀수일 때 터지는 폭탄
    int now = 1;
    while(now < n){
        //폭탄 위치 확인
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(map[i][j] == 'O'){
                    q.push({i, j});
                }
                map[i][j] = 'O';
            }
        }
        // 터지는 폭탄
        while(!q.empty()){
            int nx = q.front().first;
            int ny = q.front().second;
            map[nx][ny] = '.';
            for(int k=0; k<4; k++){
                int x = nx + dx[k];
                int y = ny + dy[k];
                if(x<0 || x>= r || y<0 || y>=c) continue;
                map[x][y] = '.';
            }
            q.pop();
        }
        now += 2;
    }
    // 출력
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << map[i][j];
        }
        cout << "\n";
    }

    return 0;
}
