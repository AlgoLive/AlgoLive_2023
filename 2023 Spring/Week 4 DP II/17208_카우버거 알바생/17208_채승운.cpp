#include <iostream>
#include <vector>

using namespace std;
int n, m, k;
int x, y;
int dp[101][301][301]; // 주문, 치즈, 감자
vector<pair<int, int> > vec;

int main(){
    cin >> n >> m >> k; // 주문, 잔여 치즈 및 감자
    for(int i=0; i<n; i++){
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
    } // 치즈/감자 주문내역

    for(int i=1; i<=n; i++){
        int cheese = vec[i-1].first;
        int potato = vec[i-1].second;
    
        for(int j=0; j<=m; j++){
            for(int a=0; a<=k; a++){
                if(cheese <= j && potato <= a){ // 둘 다 잔여량이 존재할 때만 주문처리가 가능하다.
                    dp[i][j][a] = max(dp[i-1][j-cheese][a-potato] + 1, dp[i-1][j][a]);
                } else {
                    dp[i][j][a] = dp[i-1][j][a];
                }
            }
        }
    }

    cout << dp[n][m][k] << '\n';
    return 0;
}