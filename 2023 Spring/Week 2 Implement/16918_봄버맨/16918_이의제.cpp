#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char map[200][200];
vector<pair<int, int> > bombs;
vector<pair<int, int> > emptys;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0 , 0, 1, -1};

void print(int R, int C){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << map[i][j];
        }
        cout << '\n';
    }
}

int main() {
    int R, C, N;
    
    cin >> R >> C >> N;

    for(int i = 0; i < R; i++){
        string line;
        cin >> line;

        for(int j = 0; j < C; j++){
            map[i][j] = line[j];

            if(map[i][j] == 'O')
                bombs.push_back(make_pair(i, j));
        }
    }

    for(int i = 2; i <= N; i++){
        // print(R, C);

        if(i % 2 == 0){
            copy(bombs.begin(), bombs.end(), back_inserter(emptys));

            for(int m = 0; m < bombs.size(); m++){
                for(int n = 0; n < 4; n++){
                    int nx = bombs[m].first + dx[n];
                    int ny = bombs[m].second + dy[n];

                    // cout << nx << ', ' << ny << '\n';

                    if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

                    if(map[nx][ny] == '.'){
                        emptys.push_back(make_pair(nx, ny));
                        map[nx][ny] = 'O';
                    }
                }
            }

            // for(int k = 0; k < emptys.size(); k++)
            //     cout << emptys[k].first << ', ' << emptys[k].second << '\n';

            memset(map, 'O', sizeof(map));
        } else {
            for(int j = 0; j < emptys.size(); j++){
                map[emptys[j].first][emptys[j].second] = '.';
            }
            emptys.clear();
            
            bombs.clear();
            for(int m = 0; m < R; m++){
                for(int n = 0; n < C; n++){
                    if(map[m][n] == 'O')
                        bombs.push_back(make_pair(m, n));
                }
            }
        }
    }

    print(R, C);

    return 0;
}