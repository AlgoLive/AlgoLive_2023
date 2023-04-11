#include <iostream>

using namespace std;

pair<int, int> dp[46];

int main() {
    int K;
    cin >> K;

    dp[1] = make_pair(0, 1);
    dp[2] = make_pair(1, 1);

    for(int i = 3; i <= K; i++){
        dp[i] = make_pair(dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second);
    }
    cout << dp[K].first << " " << dp[K].second;
    return 0;
}

// A

// B
// BA
// BAB
// BABBA
// BABBA BAB
// BABBA BABBA BBA
// BABBA BABBA BBABA BBABA B

// 1 0

// 0 1
// 1 1
// 1 2
// 2 3
// 3 5
// 5 8
// 8 13