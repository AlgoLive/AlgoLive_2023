#include <iostream>

using namespace std;
int n;
int arr[1001];
int dp[1001];

int main(){
    int res = 0;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    } // 입력

    dp[1] = arr[1];
    res = dp[1];
    
    for(int i=2; i<=n; i++){
        dp[i] = arr[i]; // 매 dp마다 초기화
        for(int j=1; j<i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[j] + arr[i], dp[i]);
            }
        }
        res = max(res, dp[i]); // 갱신
    }
    cout << res << '\n';
    return 0;
}