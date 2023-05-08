#include <iostream>

using namespace std;
int d[401][401];
int n, k, s, a, b;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;

    for(int i=0; i<k; i++){
        cin >> a >> b;
        d[a][b] = -1; // a가 b보다 먼저 일어나면 -1로 입력받아 처리
        d[b][a] = 1;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(d[i][k] == 1 && d[k][j] == 1){ // i가 k보다 늦게 일어나고, k가 j보다 늦게 일어나면
                    d[i][j] = 1; // i는 j보다 늦게 일어난 사건으로 확장 가능
                    d[j][i] = -1; 
                }
            }
        }
    }

    cin >> s;
    for(int i=1; i<=s; i++){
        cin >> a >> b;
        cout << d[a][b] << '\n';
    } // 사건의 전후 관계를 알고 싶은 쌍 입력

    return 0;
}