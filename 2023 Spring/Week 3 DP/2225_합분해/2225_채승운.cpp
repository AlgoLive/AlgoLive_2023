#include <iostream>

using namespace std;
int n, k;
long long dp[201][201] = { 0, }; // k개의 숫자로 n을 만드는 경우의 수를 저장
long long dpT[201][201] = { 0, }; // Top-Down 전용

long long solve(int k, int n){ // Top-Down
    if(n == 0 || k == 1) return 1;
    if(dpT[k][n] == 0){
        for(int i=n; i>=0; i--){
            dpT[k][n] += solve(k-1, i);
            dpT[k][n] = dpT[k][n] % 1000000000;
        }
    }
    return dpT[k][n];
}


int main(){
    cin >> n >> k;

    for(int i=0; i<=n; i++){
        dp[1][i] = 1; // 1개로 i를 만드는 경우의 수는 무조건 1
    }

    for(int i=2; i<=k; i++){ // Bottom-Up
        for(int j=0; j<=n; j++){
            for(int a=0; a<=j; a++){
                dp[i][j] += dp[i-1][a]; // 점화식 반영
            }
            dp[i][j] = dp[i][j] % 1000000000; // 나누기 조건
        }
    }

    cout << solve(k, n) << '\n';
    // cout << dp[k][n] << '\n';
    return 0;
}

/**
 * n, 0 -> 1
 * 
 * 1, 1 -> 1 (1)
 * 1, 2 -> 10 01 (2)
 * 1, 3 -> 100 010 001 (3)
 * 1, 4 -> (4)
 * 1, 5 -> 5
 * 
 * 2, 1 -> 2 (1)
 * 2, 2 -> 20 02 11 (3)
 * 2, 3 -> 200 020 002 110 101 011 (6)
 * 2, 4 -> 2000 0200 0020 0002 +6 (10)
 * 2, 5 -> 15로 추정
 * 
 * 3, 1 -> 3 (1)
 * 3, 2 -> 30 03 21 12 (4)
 * 3, 3 -> 300 030 003 120 102 201 210 021 012 111 (10)
 * 3, 4 -> 3 4개, 111 4개, 12면서 1이 앞일 때 3개, 2가 앞일 떄 3개, 나머지 6개 (20)
 * 3, 5 -> 25로 추정
 * 
 * 점화식: dp[k][n] = dp[k][n-1] + dp[k][n-2] + ... + dp[k][1] + dp[k][0]
*/