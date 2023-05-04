#include <iostream>
#include <vector>

using namespace std;
int n, m;
bool visited[9];
vector<int> v;

void backtrack(int cnt, int idx){
    if(cnt == m){ // m개를 모두 골랐다면 출력
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(i); // 노드 벡터에 추가
        backtrack(cnt + 1, idx + 1); // 재귀 호출
        v.pop_back(); // 부모 노드 상태로 돌아가야 하므로 마지막 노드 배제
        visited[i] = false;
    }
}

int main(){
    cin >> n >> m;
    backtrack(0, 1);
    return 0;
}