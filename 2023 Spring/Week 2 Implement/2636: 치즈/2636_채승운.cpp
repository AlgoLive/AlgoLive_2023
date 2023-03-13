#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[101][101];
int map[101][101];
int n, m;
int times = 0;
int hour = 0;

bool allmelt(){ // 치즈가 모두 녹았는지 확인
    bool flag = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 1) {
                flag = false;
            }
        }
    }
    return flag;
}

void BFS(){
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0)); // 절대 안쪽 공기에 접근하면 안 되므로 치즈 바깥으로 순회해야만 한다.
    times++;
    visited[0][0] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) continue;

            if(map[nx][ny] == 0){ // 바깥공기
                q.push(make_pair(nx, ny)); // 큐에 추가
            } else { // 무조건 치즈 테두리
                map[nx][ny] = 0; // 녹이기 (이제 바깥공기)
                hour++; // 마지막에 녹은 치즈를 저장하기 위함
            }
            visited[nx][ny] = true;
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
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);

    input();
    while(1){
        memset(visited, false, sizeof(visited));
        hour = 0;

        BFS();
        if(allmelt()) break; // 모두 녹았다면 이탈
    }
    cout << times << '\n'; // 모두 녹을 때까지 걸린 시간
    cout << hour << '\n'; // 모두 녹기 직전에 마지막으로 녹은 치즈 개수
    return 0;
}