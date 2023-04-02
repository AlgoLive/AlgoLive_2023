#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001], dp[1001];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int Min=0;
    for(int i=0; i<n; i++){
        if(Min < dp[i]){
            Min = dp[i];
        }
    }
    cout << Min;

    return 0;
}