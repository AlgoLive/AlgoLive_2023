#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int n, m, res=INF;
int map[1001][1001], dp[1001][1001][4];
//0=왼, 1=가운데, 2=오
//bottomup

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(i == 0){
                dp[i][j][0] = map[i][j];
                dp[i][j][1] = map[i][j];
                dp[i][j][2] = map[i][j];
            }
        }
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(j == 0){
                dp[i][j][0] = INF;
                dp[i][j][1] = dp[i-1][j+1][0] + map[i][j];
                dp[i][j][2] = min(dp[i-1][j+1][0], dp[i-1][j][1]) + map[i][j];
            }
            else if (j == m-1)
            {
                dp[i][j][0] = min(dp[i-1][j][1], dp[i-1][j-1][2]) + map[i][j];
                dp[i][j][1] = dp[i-1][j-1][2] + map[i][j];
                dp[i][j][2] = INF;
            }
            else
            {
                dp[i][j][0] = min(dp[i-1][j][1], dp[i-1][j-1][2]) + map[i][j];
                dp[i][j][1] = min(dp[i-1][j-1][2], dp[i-1][j+1][0]) + map[i][j];
                dp[i][j][2] = min(dp[i-1][j+1][0], dp[i-1][j][1]) + map[i][j];
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<3; j++) {
            res = min(res, dp[n - 1][i][j]);
        }
    }
    cout << res;

    return 0;
}