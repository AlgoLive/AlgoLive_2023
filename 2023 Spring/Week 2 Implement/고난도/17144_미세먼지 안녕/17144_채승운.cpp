/**
 * 17144번 - 미세먼지 안녕!
*/
#include <iostream>
#include <queue>

using namespace std;

int map[51][51];
int add[51][51];
int r, c, t, total;
int upr, downr;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void input(){ // 입력
    bool flag = false;

    cin >> r >> c >> t;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> map[i][j];
            if(map[i][j] == -1){ // 공기청정기가 놓인 곳
                if(!flag){
                    upr = i; // 공기청정기의 윗 좌표의 행 (상행)
                    flag = true;
                } else {
                    downr = i; // 공기청정기의 밑 좌표의 행 (하행)
                }
            }
        }
    }
}

void spreadDust(){ // 미세먼지 확산
    queue<pair<pair<int, int>, int> > q;
    for(int i=0; i<r; i++){ 
        for(int j=0; j<c; j++){
            if(map[i][j] <= 0) continue; // 0이나 -1은 제외
            q.push(make_pair(make_pair(i, j), map[i][j])); // 확산될 먼지를 모두 담음
        }
    }

    while(!q.empty()){ // BFS
            int cr = q.front().first.first;
            int cc = q.front().first.second;
            int curval = q.front().second;
            q.pop();
            int dir = 4;

            for(int k=0; k<4; k++){ // 먼지 4방향으로 퍼짐
                int nr = cr + dr[k];
                int nc = cc + dc[k];
                if(nr < 0 || nr >= r || nc < 0 || nc >= c) dir--; // 범위 이탈
                if(map[nr][nc] == -1) dir--; // 공기청정기
            }
            int spreadval = curval / 5;
            map[cr][cc] = map[cr][cc] - spreadval * dir; // 확산을 위해 기존 먼지에서 퍼진 먼지를 제외
        
            for(int i=0; i<4; i++){ // 미세먼지 확산
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                if(nr < 0 || nr >= r || nc < 0 || nc >= c) continue; // 범위 이탈
                if(map[nr][nc] == -1) continue; // 공기청정기
                map[nr][nc] = map[nr][nc] + spreadval;
            }
    }
}

void airConditioner(){ // 공기청정기 (위치를 움직이지 않는다)
    
    // 위쪽 구간
    for(int i=upr-1; i>0; i--){ // 왼쪽 길
        map[i][0] = map[i-1][0];
    }

    for(int i=0; i<c-1; i++){ // 위쪽 길
        map[0][i] = map[0][i+1];
    }

    for(int i=0; i<upr; i++){ // 오른쪽 길
        map[i][c-1] = map[i+1][c-1];
    }

    for(int i=c-1; i>1; i--){ // 아래쪽 길
        map[upr][i] = map[upr][i-1];
    }
    map[upr][1] = 0;

    // 아래쪽 구간
    for(int i=downr+1; i<r-1; i++){ // 왼쪽 길
        map[i][0] = map[i+1][0];
    }

    for(int i=0; i<c-1; i++){ // 아래쪽 길
        map[r-1][i] = map[r-1][i+1];
    }

    for(int i=r-1; i>downr; i--){ // 오른쪽 길
        map[i][c-1] = map[i-1][c-1];
    }

    for(int i=c-1; i>1; i--){ // 위쪽 길
        map[downr][i] = map[downr][i-1];
    }
    map[downr][1] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    input();
    while(t--){ // t초 동안 미세먼지의 확산 -> 공기청정기의 작동이 일어난다.
        spreadDust();
        airConditioner();
    }
    for(int i=0; i<r; i++){ // 결과
        for(int j=0; j<c; j++){
            if(map[i][j] != -1){
                answer += map[i][j];
            }
        }
    }
    cout << answer;
    return 0;
}