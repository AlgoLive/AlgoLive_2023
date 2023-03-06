#include <iostream>
#include <vector>

using namespace std;

int map[25][25];
int visited[25][25];
vector<pair<int, int> > home;
vector<int> complex;

int cnt;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(pair<int, int> start, int N){
    int x = start.first;
    int y = start.second;

    if(visited[x][y] != 0)
        return;

    visited[x][y] = 1;
    cnt++;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(map[nx][ny] == 0) continue;

        DFS(make_pair(nx, ny), N);
    }
}

int main() {
    int N;

    cin >> N;
    for(int i = 0; i < N; i++){
        string line;
        
        cin >> line;
        for(int j = 0; j < line.size(); j++){
            map[i][j] = line[j] - '0';
            if(map[i][j] == 1)
                home.push_back(make_pair(i, j));
        }
    }

    for(int i = 0; i < home.size(); i++){
        if(visited[home[i].first][home[i].second] == 0){
            DFS(home[i], N);
            complex.push_back(cnt);
            cnt = 0;
        }
    }

    sort(complex.begin(), complex.end());
    cout << complex.size() << '\n';
    for(int i = 0; i < complex.size(); i++)
        cout << complex[i] << '\n';

    return 0;
}