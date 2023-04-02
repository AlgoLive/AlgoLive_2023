#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, K;
pair<int, int> jewel[101];
int dp[101][100001];

int main() {
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        int W, V;
        cin >> W >> V;
        jewel[i + 1] = make_pair(W, V);
    }

    sort(jewel, jewel + N + 1);

    for(int i = 0; i <= N; i++)
        // cout << jewel[i].first << ' ' << jewel[i].second << '\n';

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            if(j >= jewel[i].first) {
                dp[i][j] = max(dp[i - 1][j - jewel[i].first] + jewel[i].second, dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // for(int i = 0; i <= N; i++){
    //     for(int j = 0; j <= K; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << dp[N][K];

    return 0;
}
// 0 1 2 3 4 5 6 7
// 0 0 0 0 0 0 0 0
// 0 0 0 6 6 6 6 6
// 0 0 0 6 8 8 8 14 
// 0 0 0 6 8 12 12 14
// 0 0 0 6 8 12 13 14
