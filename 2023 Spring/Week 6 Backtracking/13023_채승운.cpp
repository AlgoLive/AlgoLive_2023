#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
bool visited[2001];
int n, m;
int flag = 0;
vector<int> v[2001];

void backtrack(int cnt, int idx){
    if(cnt == 4){ // 성공
        flag = 1;
        return;
    }

    for(int i=0; i<v[idx].size(); i++){
        if(visited[v[idx][i]]) continue; // idx 친구의 친구 목록을 순회하며 DFS를 실행한다.
        visited[v[idx][i]] = true;
        backtrack(cnt + 1, v[idx][i]);
        visited[v[idx][i]] = false;
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    } // 친구 목록을 벡터 리스트 형태로 저장한다. 즉 친구 0과 연결된 친구들을 입력순으로 담는 것이다.

    for(int i=0; i<n; i++){ // 친구 하나씩 출발시키며 친구관계 5명이 만들어지는지 확인한다.
        memset(visited, 0, sizeof(visited)); // 매 케이스마다 초기화
        visited[i] = true; // 뻘짓: 시작점도 당연히 방문하므로 true인데 이를 누락시켜서 시간을 날렸다.
        backtrack(0, i);
        if(flag) break; // 성공했으면 이탈
    }
    cout << flag << '\n';
    return 0;    
}