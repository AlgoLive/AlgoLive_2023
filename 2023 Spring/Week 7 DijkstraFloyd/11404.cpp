#include <iostream>

#define INF 500000000
using namespace std;
int n, m;
int dist[101][101];

int main(){
    cin >> n >> m;

    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(dist[a][b] > c){
            dist[a][b] = c;
        }
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j] >= INF){
                cout << 0 << " ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}