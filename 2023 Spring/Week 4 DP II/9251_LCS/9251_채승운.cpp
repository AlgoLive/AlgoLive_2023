#include <iostream>

using namespace std;
int dp[1001][1001] = { 0, };

int main(){
    string s1, s2;
    cin >> s1;
    cin >> s2;

    for(int i=1; i<=s1.size(); i++){ // LIS과 구도가 유사하다.
        for(int j=1; j<=s2.size(); j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[s1.size()][s2.size()];
    return 0;
}