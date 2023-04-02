#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];
int dp[1000];
int N;
int result;

int main() {
    cin >> N;
    fill(dp, dp + N, 1);

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[i]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    result = dp[0];
    for(int i = 0; i < N; i++){
        if(dp[i] > result) result = dp[i];
    }
    
    cout << result;
    
    return 0;
}