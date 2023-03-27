#include <iostream>
using namespace std;

int n, k;
long long dp[201][201]; //dp[k][n] k개 숫자로 n
// bottomup

int main(){
    cin >> n >> k;
    for(int i=0; i<=n; i++){
        dp[1][i] = 1;
    }
    for(int i=2; i<=k; i++){
        for(int j=0; j<=n; j++){
            for(int z=0; z<=j; z++){
                dp[i][j] += dp[i-1][j-z];
            }
            dp[i][j] = dp[i][j] % 1000000000;
        }
    }

    cout << dp[k][n];

    return 0;
}