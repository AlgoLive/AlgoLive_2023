#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

int M, N;
int map[1001][1001];
bool visited[1001][1001];
vector<tuple<int, int, int> > tomato;
int tomato_cnt;
int depth;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int BFS(){
    queue<tuple<int, int, int> > q;
    int result;

    for(int i = 0; i < tomato.size(); i++)
        q.push(make_tuple(get<0>(tomato[i]), get<1>(tomato[i]), get<2>(tomato[i])));
    
    if(q.empty()) return 0;
    
    while(true){
        tuple<int, int, int> cur = q.front();
        q.pop();
        
        // cout << get<0>(cur) << get<1>(cur) << get<2>(cur) << '\n';
        tomato_cnt--;
        // cout << tomato_cnt << '\n';

        for(int i = 0; i < 4; i++){
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];

            if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

            if(map[nx][ny] == 0 && visited[nx][ny] == false){
                q.push(make_tuple(nx, ny, get<2>(cur) + 1));
                visited[nx][ny] = true;
            }
        }
        if(q.empty()){
            result = get<2>(cur);
            break;
        }
    }
    return result;
};

int main() {
    int cnt = 0;
    memset(map, -1, sizeof(map));
    memset(visited, false, sizeof(visited));

    cin >> N >> M; // 훼이크
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) {
                tomato.push_back(make_tuple(i, j, 0));
                visited[i][j] = true;
                tomato_cnt++; // 제일 중요  
                cnt++;
            }else if (map[i][j] == 0) {
                tomato_cnt++;
            }
        }
    }
    if(cnt == 0) { // 들 익은 토마토가 하나도 없을 경우
        cout << -1;
        return 0;
    }
    depth = BFS();

    if(tomato_cnt > 0) cout << -1;
    else cout << depth;

    // for(in)

    return 0;
}