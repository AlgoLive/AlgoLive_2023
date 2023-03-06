#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int farm[50][50];
int visited[50][50];
vector<pair<int, int> > K_cabbage;
int result = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(pair<int, int> start, int M, int N, int depth){
    int x = start.first;
    int y = start.second;

    if(visited[x][y] != 0)
        return;

    visited[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
        if(farm[nx][ny] == 0) continue;

        DFS(make_pair(nx, ny), M, N, depth + 1);
    }
    if(depth == 0)
        result++;
}

int main() {
    int T;
    int M, N, K;
    int X, Y;

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> M >> N >> K;

        for(int j = 0; j < K; j++){
            cin >> X >> Y;
            farm[X][Y] = 1;
            K_cabbage.push_back(make_pair(X, Y));
        }

        for(int i = 0; i < K_cabbage.size(); i++){
            DFS(K_cabbage[i], M, N, 0);
            
        }

        cout << result << '\n';

        memset(farm, 0, sizeof(farm));
        memset(visited, 0, sizeof(visited));
        K_cabbage.clear();
        result = 0;
    }

    return 0;
}