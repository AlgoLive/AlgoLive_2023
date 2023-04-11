#include <iostream>
#include <cmath>

using namespace std;

int N, M;
int fuel[6][6];
int dp[6][6][3];

int min(int a, int b, int c){
    return min(min(a, b), c);
}

int min(int a, int b, int c, int d){
    return min(min(a, b, c), d);
}

int main() {
    int result = 0;

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> fuel[i][j];
        }
    }

    for(int j = 0; j < M; j++){
        dp[0][j][0] = fuel[0][j];
        dp[0][j][1] = fuel[0][j];
        dp[0][j][2] = fuel[0][j];
    }

    for(int i = 1; i < N; i++){
        for(int j = 0; j < M; j++){
            if(j == 0){
                dp[i][j][0] = 9999;
                dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + fuel[i][j];
                dp[i][j][2] = min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + fuel[i][j];
            }
            else if(j == M - 1){
                dp[i][j][0] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + fuel[i][j];
                dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + fuel[i][j];
                dp[i][j][2] = 9999;
            }
            else {
                dp[i][j][0] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + fuel[i][j];
                dp[i][j][1] = min(dp[i - 1][j ][0], dp[i - 1][j][2]) + fuel[i][j];
                dp[i][j][2] = min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + fuel[i][j];
            }
        }
    }

    result = dp[N - 1][0][0];
    
        for(int j = 0; j < M; j++){
            for(int k = 0; k < 3; k++){
                if(dp[N - 1][j][k] < result)
                    result = dp[N - 1][j][k];
            }
        }
    

    // result = dp[N - 1][0];
    // for(int j = 1; j < M; j++){
    //     if(dp[N - 1][j] < result)
    //         result = dp[N - 1][j];
    // }
    
    cout << result;

    return 0;
}