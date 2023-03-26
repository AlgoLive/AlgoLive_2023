#include <iostream>
#include <cstring>

using namespace std;
int n, m;
int T;
int coin[21];
int dp[10001];


int main(){
    cin >> T;

    for(int a=0; a<T; a++){
        memset(coin, 0, sizeof(coin));
        memset(dp, 0, sizeof(dp)); // 테케마다 초기화

        cin >> n;
        for(int i=0; i<n; i++){ // 동전 입력
            cin >> coin[i];
        }
        cin >> m;

        dp[0] = 1; // 0원을 만드는 경우의 수는 1 (아무것도 안 하기)
        for(int i=0; i<n; i++){ // 코인의 종류가 하나씩 추가되면서
            for(int j=coin[i]; j<=m; j++){ // 경우의 수를 찾아간다.
                dp[j] += dp[j-coin[i]];
            }
        }
        cout << dp[m] << '\n';
    }
    return 0;
}

/* 1/5/10원 사용
0 - 1 (1개)
1 - 1 (1개)
2 - 1/1 (1개)
3 - 1/1/1 (1개)
4 - 1/1/1/1 (1개)
5 - 1/1/1/1/1, 5 (2개)
6 - 1/1/1/1/1/1, 1/5 (2개)
7 - 1/1/1/1/1/1/1, 1/1/5 (2개)
8 - 1/1/1/1/1/1/1/1, 1/1/1/5 (2개)
9 - 1/1/1/1/1/1/1/1/1, 1/1/1/1/5 (2개)
10 - 1/1/1/1/1/1/1/1/1/1, 1/1/1/1/1/5, 5/5, 10 (4개)
점화식: dp[a] += dp[a-코인]?
*/