#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, w, v;
int dp[101][100001];    // n개의 보석이 k 용량까지 가능할 때 가치
vector<pair<int, int>> bag;

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> w >> v;
        bag.push_back({w, v});
    }
    for(int i=1; i<=n; i++){
        int weight = bag[i-1].first;
        int val = bag[i-1].second;
        for(int j=1; j<=k; j++){
            if(j < weight){  // 못담는 경우
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + val);
            }
        }
    }
    cout << dp[n][k];

    return 0;
}