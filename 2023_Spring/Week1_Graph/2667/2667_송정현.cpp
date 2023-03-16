#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;



int n, map[25][25], cnt;
bool vis[25][25];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1}; //상하좌우

void bfs(int a, int b) {
    cnt = 0;
    queue<pair<int, int>> q;
    vis[a][b] = true;
    cnt++;
    q.push({a,b});

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(map[nx][ny] && !vis[nx][ny]) {
                vis[nx][ny] = true;
                cnt++;
                q.push({nx, ny});

            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<n; j++){
            map[i][j] = str[j]-'0';
        }
    }
    vector<int> v;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 1 && !vis[i][j]){
                bfs(i, j);
                v.push_back(cnt);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }

    return 0;
}
