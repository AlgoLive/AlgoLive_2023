#include <iostream>

using namespace std;
int n;
int arr[1001];
int dp[1001];

int main(){
    int res = 1;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    } // 입력

    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = 1; // 매 dp마다 초기화
        for(int j=1; j<i; j++){
            if(arr[i] < arr[j]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        res = max(res, dp[i]); // 갱신
    }
    cout << res << '\n';
    return 0;
}