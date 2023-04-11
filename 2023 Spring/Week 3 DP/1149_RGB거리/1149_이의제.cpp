#include <iostream>
#include <cmath>

using namespace std;

int N;
int map[1000][3];
int dp[1000][3][3];
int result;

int main () {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> map[i][j];
        }
    }

    for(int j = 0; j < 3; j++){
        dp[0][j][0] = map[0][j];
        dp[0][j][1] = map[0][j];
        dp[0][j][2] = map[0][j];
    }

    for(int i = 1; i < N; i++){
        dp[i][0][0] = 10000001;
        dp[i][0][1] = min(dp[i - 1][1][0], dp[i - 1][1][2]) + map[i][0];
        dp[i][0][2] = min(dp[i - 1][2][0], dp[i - 1][2][1]) + map[i][0];

        dp[i][1][0] = min(dp[i - 1][0][1], dp[i - 1][0][2]) + map[i][1];
        dp[i][1][1] = 10000001;
        dp[i][1][2] = min(dp[i - 1][2][0], dp[i - 1][2][1]) + map[i][1];

        dp[i][2][0] = min(dp[i - 1][0][1], dp[i - 1][0][2]) + map[i][2];
        dp[i][2][1] = min(dp[i - 1][1][0], dp[i - 1][1][2]) + map[i][2];
        dp[i][2][2] = 10000001;
    }

    // for(int i = 0; i < N; i++){
    //     cout << "(" << dp[i][0][0] << ", " << dp[i][0][1] << ", " << dp[i][0][2] << ") ";
    //     cout << "(" << dp[i][1][0] << ", " << dp[i][1][1] << ", " << dp[i][1][2] << ") ";
    //     cout << "(" << dp[i][2][0] << ", " << dp[i][2][1] << ", " << dp[i][2][2] << ") " << '\n';
    // }

    result = dp[N - 1][0][1];
    for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
            if(result >= dp[N - 1][j][k])
                result = dp[N - 1][j][k];
        }
    }
    cout << result;

    return 0;
}