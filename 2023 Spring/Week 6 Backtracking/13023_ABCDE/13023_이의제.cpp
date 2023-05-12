#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
bool visited[2001];
vector<int> list[2001];

bool DFS(int start, int depth){
    bool result;

    visited[start] = true;

    // cout << "start: " << start << " depth: " << depth << '\n';

    if(depth >= 4){
        return true;
    }

    for(int i = 0; i < list[start].size(); i++) {
        if(visited[list[start][i]] == false){
            result = DFS(list[start][i], depth + 1);
            if(result == true) break;
        }
    }

    visited[start] = false;

    return result;
}

int main() {
    memset(visited, false, sizeof(visited));
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;

        list[a].push_back(b);
        list[b].push_back(a);
    }

    for(int i = 0; i < N; i++){
        if(DFS(i, 0)){
            cout << "1";
            return 0;
        }
    }

    cout << "0";

    return 0;
}