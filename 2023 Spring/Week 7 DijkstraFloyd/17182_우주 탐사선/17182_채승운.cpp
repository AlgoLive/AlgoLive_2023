#include <iostream>


using namespace std;
int n, k;
int sum = 987654321;
int dist[11][11];
bool visited[11];

void DFS(int now, int nowsum, int cnt){ // 모든 행성 다 탐지해야 함 - 백트래킹 활용
    if(cnt == n){ // n개 행성 모두 탐사 시 최솟값 갱신
        sum = min(sum, nowsum);
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue; // i번째 행성을 방문함/방문하지 않음으로 백트래킹
        visited[i] = true;
        DFS(i, nowsum + dist[now][i], cnt + 1);
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k; // 입력
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> dist[i][j];
        }
    }

    for(int k=0; k<n; k++){ // 플로이드
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    visited[k] = true; // 시작 지점을 앞서서 방문처리
    DFS(k, 0, 1);
    cout << sum << '\n';
    return 0;
}