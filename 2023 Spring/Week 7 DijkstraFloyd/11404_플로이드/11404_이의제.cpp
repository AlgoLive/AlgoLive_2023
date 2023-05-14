#include <iostream>
#include <algorithm>

#define INF 100000000

using namespace std;

int n, m;
int D[101][101];

int main() {
    cin >> n;
    cin >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            D[i][j] = INF;

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;

        D[a][b] = min(D[a][b], w);
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) continue;

                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << ((D[i][j] == INF) ? 0 : D[i][j]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}