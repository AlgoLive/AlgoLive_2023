#include <iostream>
#include <cstring>
using namespace std;

int n, k;
long long dp[201][201]; //dp[k][n] k개 숫자로 n
// topdown

long long DP(int k, int n){
    if(k == 1 || n == 0)    return 1;
    if(dp[k][n] != 0)   return dp[k][n];
    for(int i=n; i>=0; i--){
        dp[k][n] += DP(k-1, i);
        dp[k][n] = dp[k][n] % 1000000000;
    }
    return dp[k][n];
}

int main(){
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));

    cout << DP(k, n);

    return 0;
}