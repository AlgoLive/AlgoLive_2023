#include <iostream>

using namespace std;

int N;
int arr[1000];
int dp[1000];

int main() {
    int answer;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[j] + arr[i], dp[i]);
            }
        }
        // dp[i] += arr[i];
    }

    answer = dp[0];
    for(int i = 0; i < N; i++){
        if(answer < dp[i])
            answer = dp[i];
    }
    cout << answer;

    return 0;
}

// 1 100 2 50 60 3 5 6 7 8
// 1 101 
