#include <iostream>
#include <algorithm>
using namespace std;

// dp 배열에 무엇을 넣을지 결정 먼저
// 포도주를 넣자
int dp[10001] = {0};
int n, grape[10001];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> grape[i];
    }
    dp[0] = 0;
    dp[1] = dp[0] + grape[1]; // 1번(자기꺼) 먹고 그 앞에꺼 먹고
    dp[2] = dp[1] + grape[2]; // 2번(자기꺼) 먹고 그 앞에꺼 먹고
    dp[3] = max(max(dp[2], dp[1]+grape[3]), dp[0]+grape[2]+grape[3]);
    // 자기꺼 안먹고 최대, 자기꺼 먹고 앞에 비우고 그전까지 최대, 자기꺼 먹고 그 앞에꺼 먹고 그 앞에 비우고 그전까지 최대
    for(int i=4; i<=n; i++){
        dp[i] = max(max(dp[i-1], dp[i-2]+grape[i]), dp[i-3]+grape[i-1]+grape[i]);
    }
    cout << dp[n];

    return 0;
}