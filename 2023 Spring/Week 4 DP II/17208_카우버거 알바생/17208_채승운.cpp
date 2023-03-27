#include <iostream>
#include <vector>

using namespace std;
int n, k, w, v;
int dp[101][100001];
vector<pair<int, int> > vec;

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> w >> v;
        vec.push_back(make_pair(w, v));
    } // 무게와 가치 입력

    for(int i=1; i<=n; i++){
        int weight = vec[i-1].first;
        int val = vec[i-1].second;
    
        for(int j=0; j<=k; j++){
            if(weight <= j){
                dp[i][j] = max(dp[i-1][j-weight] + val, dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout << dp[n][k] << '\n';
    return 0;
}