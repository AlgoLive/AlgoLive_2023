#include <iostream>

using namespace std;

long long N, K;
long long dp[201][201];

int main() {
    cin >> N >> K;

    for(long long i = 1; i <= K; i++)
        dp[i][0] = 1;

    for(long long i = 1; i <= K; i++){
        for(long long j = 1; j <= N; j++){
            if(i == 1)
                dp[i][j] = 1;
            else if(j == 1)
                dp[i][j] = i;
            else {
                for(long long k = 0; k <= j; k++)
                    dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 1000000000;
            }
        }
    }

    // for(long long i = 1; i <= K; i++){
    //     for(long long j = 0; j <= N; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[K][N];

    return 0;
}

// 결국 답지 봄

// 6 1 = 1
// 6

// 6 2 = 5
// 1 5
// 2 4
// 3 3
// 4 2
// 5 1

// 6 3 = 10 
// 1 1 4
// 1 4 1
// 4 1 1

// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1

// 2 2 2

// 6 4
// (
// 1 1 1 3
// 1 1 3 1
// 1 3 1 1
// 3 1 1 1

// 1 1 2 2
// 1 2 1 2
// 1 2 2 1
// 2 1 1 2
// 2 1 2 1
// 2 2 1 1

// )


// (6, 4)
// = (6, 1) * 4 + (6, 2) * (3 + 3C2) + (6, 3) * 4 + 10
// = 4 + 30 + 40 + 10
// = 84

// (6, 3)
// = (6, 1) * 3 + (6, 2) * 3 + 10
