#include <iostream>

using namespace std;
int n;
int dp[1000001] = { 0, };

int main(){
    cin >> n;
    dp[1] = 0; // 연산 안해도 됨
    dp[2] = 1;
    dp[3] = 1;

    for(int i=4; i<=n; i++){
        if(i % 6 == 0){ // 6의 배수인 경우 -> 1, 2, 3번 모두 비교
            dp[i] = min(dp[i-1], min(dp[i/3], dp[i/2])) + 1;
        } else if(i % 3 == 0){ // 3의 배수인 경우 -> 1, 3번
            dp[i] = min(dp[i-1], dp[i/3]) + 1;
        } else if(i % 2 == 0){ // 2의 배수인 경우 -> 2, 3번
            dp[i] = min(dp[i-1], dp[i/2]) + 1;
        } else { // 3번
            dp[i] = dp[i-1] + 1;
        }
    }

    cout << dp[n];
    return 0;
}