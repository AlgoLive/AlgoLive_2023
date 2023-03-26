#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[101][101];
bool visited[101][101];
int melt[101][101];
int n, m, times;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool meltcheck(){
    bool flag = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(melt[i][j] >= 2){ // 녹일 수 있는 치즈들을 다 녹인다.
                map[i][j] = 0;
                flag = true;
            }
        }
    }
    return flag;
}

void BFS(){
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0)); // r와 c

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if(visited[r][c]) continue;
        visited[r][c] = true;

        for(int i=0; i<4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

            if(map[r][c] == 0 && map[nr][nc] == 1){ // 공기 노출 감지
                melt[nr][nc]++;
            } else if(!visited[nr][nc]){
                q.push(make_pair(nr, nc));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    } // 입력

    times = 0;
    while(1){
        memset(visited, 0, sizeof(visited)); // 매 웨이브마다 초기화 할 때는 memset을 활용하자 <cstring>
        memset(melt, 0, sizeof(melt));

        BFS(); // 탐색과 녹이기를 분리하는 것이 핵심이었다.
        if(meltcheck()) times++;
        else break;
    }
    cout << times << '\n';
    return 0;
}