#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, t, k, s;
int dp[101][10001];
vector<pair<int, int>> sub;

int main(){
    cin >> n >> t;
    for(int i=0; i<n; i++){
        cin >> k >> s;
        sub.push_back({k, s});
    }
    for(int i=1; i<=n; i++){
        int time = sub[i-1].first;
        int score = sub[i-1].second;

        for(int j=1; j<=t; j++){
            if(j < time){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-time] + score);
            }
        }
    }
    cout << dp[n][t];

    return 0;
}