#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int max_height = 1;
int map[100][100];
bool visited[100][100];
int result = 1;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS(pair<int, int> start, int height){
    if(visited[start.first][start.second] == true)
        return;

    visited[start.first][start.second] = true;

    for(int i = 0; i < 4; i++){
        int nx = start.first + dx[i];
        int ny = start.second + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if(visited[nx][ny] == false && map[nx][ny] > height)
            DFS(make_pair(nx, ny), height);
    }
};

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] > max_height)
                max_height = map[i][j];
        }
    }
    memset(visited, false, sizeof(visited));

    for(int i = 1; i <= max_height; i++){
        int cnt = 0;
        for(int m = 0; m < N; m++){
            for(int n = 0; n < N; n++){
                if(visited[m][n] == false && map[m][n] > i){
                    DFS(make_pair(m, n), i);
                    cnt++;
                }
            }
        }
        memset(visited, false, sizeof(visited));

        // cout << result << cnt << '\n';
        result = max(result, cnt);
    }

    cout << result;

    return 0;
}