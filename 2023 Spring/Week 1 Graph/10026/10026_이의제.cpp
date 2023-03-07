#include <iostream>
#include <cstring>

using namespace std;

char figure[100][100];
bool visited[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS(pair<int, int> start, int N){
    int x = start.first;
    int y = start.second;

    if(visited[x][y])
        return;
    
    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(figure[x][y] != figure[nx][ny]) continue;

        DFS(make_pair(nx, ny), N);
    }
}

void DFS2(pair<int, int> start, int N){
    int x = start.first;
    int y = start.second;

    if(visited[x][y])
        return;
    
    visited[x][y] = true;
    // cout << x << ' ' << y << '\n';

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(figure[x][y] != figure[nx][ny]) {
            char cur = figure[x][y];
            char next = figure[nx][ny];
            if(!((cur == 'R' || cur == 'G') && (next == 'R' || next == 'G')))
                continue;
        }

        DFS2(make_pair(nx, ny), N);
    }
}

int main() {
    int N;
    int result[2] = {0, 0};

    memset(figure, false, sizeof(figure));

    cin >> N;
    for(int i = 0; i < N; i++){
        string line;
        cin >> line;

        for(int j = 0; j < line.size(); j++){
            figure[i][j] = line[j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                DFS(make_pair(i, j), N);
                result[0]++;
            }
        }
    }

    memset(visited, false, sizeof(visited));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                DFS2(make_pair(i, j), N);
                result[1]++;
            }
        }
    }

    cout << result[0] << ' ' << result[1];
    return 0;
}