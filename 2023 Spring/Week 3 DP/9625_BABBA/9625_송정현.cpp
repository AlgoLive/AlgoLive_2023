#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;
vector<pair<int, int>> dp;

int main(){
    cin >> k;
    dp.push_back({1,0}); // dp[0]
    dp.push_back({0,1}); // dp[1]
    dp.push_back({1,1}); // dp[2]
    dp.push_back({1,2}); // dp[3]

    for(int i=4; i<=k; i++){
        int a1 = dp[i-1].first;
        int b1 = dp[i-1].second;
        int a2 = dp[i-2].first;
        int b2 = dp[i-2].second;
        dp.push_back({a1+a2, b1+b2});
    }
    cout << dp[k].first << " " << dp[k].second;

    return 0;
}