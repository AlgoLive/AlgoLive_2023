#include<iostream>
#define INF 1e9

using namespace std;

int N, M;
int d[101][101];

void floyd(int n){
    // 플로이드 워셜 알고리즘
    for(int k=1; k<=n; k++){// k = 거쳐가는 노드
        for(int i=1; i<=n; i++){// i = 출발 노드
            for(int j=1; j<=n; j++){// j = 도착 노드
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main(){
    int a, b, c;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            d[i][j] = INF;
        }
    }
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        if(d[a][b] > c)
            d[a][b] = c;
    }

    floyd(N);
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i == j || d[i][j] == INF)
                cout << 0 << " ";
            else
                cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}