#include<iostream>
#define INF 1e9

using namespace std;

int n, k;
int d[401][401] = {0,};

void floyd(int n){
    // 플로이드 워셜 알고리즘
    for(int k=1; k<=n; k++){// k = 거쳐가는 노드
        for(int i=1; i<=n; i++){// i = 출발 노드
            for(int j=1; j<=n; j++){// j = 도착 노드
                if(d[i][j] == 0){
                    if(d[i][k] == d[k][j]){
                        d[i][j] = d[i][k];
                        d[j][i] = -d[i][j];
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, s;
    cin >> n >> k;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        d[a][b] = -1;
        d[b][a] = 1;
    }
    floyd(n);
    cin >> s;
    for(int i=0; i<s; i++){
        cin >> a >> b;
        cout << d[a][b] << "\n";
    }

    return 0;
}