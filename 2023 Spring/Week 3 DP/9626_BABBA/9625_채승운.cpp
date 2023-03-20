#include <iostream>

using namespace std;
int k;
int dp[46][2];

int main(){
    cin >> k;
    dp[0][0] = 1; // A
    dp[0][1] = 0; //

    dp[1][0] = 0; // B
    dp[1][1] = 1; 

    dp[2][0] = 1; // BA
    dp[2][1] = 1;

    for(int i=3; i<=k; i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }
    cout << dp[k][0] << " " << dp[k][1];
    return 0;
}