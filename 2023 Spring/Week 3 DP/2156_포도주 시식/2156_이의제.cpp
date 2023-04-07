#include <iostream>
#include <cmath>

using namespace std;

int n;
int wine[10001];
int dp[10001];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> wine[i];

    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    dp[3] = max(max(wine[1] + wine[2], wine[1] + wine[3]), wine[2] + wine[3]);

    for(int i = 4; i <= n; i++){
        dp[i] = max(max(dp[i - 1], wine[i] + dp[i - 2]), wine[i] + wine[i - 1] + dp[i - 3]);
    }

    cout << dp[n];
    return 0;
}

// 6 10 13     9