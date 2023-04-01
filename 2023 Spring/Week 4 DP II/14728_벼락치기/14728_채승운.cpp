#include <iostream>
#include <vector>

using namespace std;
int n, t, k, s;
int dp[101][10001];
vector<pair<int, int> > vec;

int main(){
    cin >> n >> t; // 단원수와 총시간
    for(int i=0; i<n; i++){
        cin >> k >> s;
        vec.push_back(make_pair(k, s));
    } // 공부시간과 배점

    for(int i=1; i<=n; i++){
        int weight = vec[i-1].first;
        int val = vec[i-1].second;
    
        for(int j=0; j<=t; j++){
            if(weight <= j){
                dp[i][j] = max(dp[i-1][j-weight] + val, dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout << dp[n][t] << '\n';
    return 0;
}