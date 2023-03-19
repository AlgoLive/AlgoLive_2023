#include <iostream>
#include <queue>

using namespace std;
struct phase { // 두 공의 좌표와, 움직인 횟수를 저장
    int rx, ry, bx, by, cnt;
    phase(int x1, int y1, int x2, int y2, int d){
        rx = x1;
        ry = y1;
        bx = x2;
        by = y2;
        cnt = d;
    }
};
int n, m;
char map[11][11];
bool visited[11][11][11][11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void moveball(int &x, int &y, int &cnt, int dir){ // dir 방향으로 공 이동
    while(map[x + dx[dir]][y + dy[dir]] != '#' && map[x][y] != 'O'){
        x += dx[dir];
        y += dy[dir];
        cnt++;
    }
}

void BFS(int Rx, int Ry, int Bx, int By){
    queue<phase> q;
    visited[Rx][Ry][Bx][By] = true;
    q.push(phase(Rx, Ry, Bx, By, 0));

    while(!q.empty()){
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int cnt = q.front().cnt;
        q.pop();

        if(cnt >= 10) break; // 10번 이상 움직이면 실패

        for(int i=0; i<4; i++){
            int newrx = rx;
            int newry = ry;
            int newbx = bx;
            int newby = by;
            int newcnt = cnt + 1;

            int rmove = 0;
            int bmove = 0;

            moveball(newbx, newby, bmove, i); // 파란 공 먼저 이동 (실패 경우를 먼저 따져야 함)
            moveball(newrx, newry, rmove, i); //  빨간 공 이동

            if(map[newbx][newby] == 'O') continue; // 실패
            if(map[newrx][newry] == 'O'){ // 성공
                cout << newcnt;
                return;
            }

            if(newrx == newbx && newry == newby){ // 둘이 나란한 위치에서 같이 움직이며 충돌(결합)한 경우
                if(rmove > bmove){ // 빨강이 더 많이 움직였다? 빨강이 한 칸 양보해야 함
                    newrx -= dx[i];
                    newry -= dy[i];
                } else {
                    newbx -= dx[i];
                    newby -= dy[i];
                }
            }

            if(!visited[newrx][newry][newbx][newby]){
                visited[newrx][newry][newbx][newby] = true;
                q.push(phase(newrx, newry, newbx, newby, newcnt));
            }
        }
    }
    cout << -1; // 최종 실패
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    int rx, ry, bx, by;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<m; j++){
            map[i][j] = str[j];
            if(map[i][j] == 'R'){ // 빨간 공 좌표
                rx = i;
                ry = j;
            } else if(map[i][j] == 'B'){ // 파란 공 좌표
                bx = i;
                by = j;
            }
        }
    }
    BFS(rx, ry, bx, by);
    return 0;
}