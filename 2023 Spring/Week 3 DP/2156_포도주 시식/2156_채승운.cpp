#include <iostream>

using namespace std;
int n;
int dp[10001] = { 0, };
int grape[10001];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> grape[i];
    }

    dp[0] = 0;
    dp[1] = grape[1];
    dp[2] = dp[1] + grape[2];
    dp[3] = max(dp[2], max(dp[0] + grape[2] + grape[3], dp[1] + grape[3]));
    
    for(int i=4; i<=n; i++){ // 점화식 일반화
        dp[i] = max(dp[i-1], max(dp[i-3] + grape[i-1] + grape[i], dp[i-2] + grape[i]));
    }
    cout << dp[n];
    return 0;
}
