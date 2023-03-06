#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int cnt = 0;
int map[26][26];
bool visited[26][26];
int result[626] = { 0, };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int r, int c){
    queue<pair<int, int> > q;
    q.push(make_pair(r, c));
    visited[r][c] = true;
    result[cnt]++; // cnt번째 단지 내 개수

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(map[nx][ny] == 1){
                if(!visited[nx][ny]){
                    result[cnt]++;
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(visited, false, sizeof(visited)); // false로 초기화

    cin >> n;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<n; j++){
            map[i][j] = str[j] - '0';
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 1){
                if(!visited[i][j]){
                    BFS(i, j);
                    cnt++;
                }
            }
        }
    }

    cout << cnt << '\n';
    sort(result, result + cnt);
    for(int i=0; i<cnt; i++){
        cout << result[i] << '\n';
    }
    return 0;
}