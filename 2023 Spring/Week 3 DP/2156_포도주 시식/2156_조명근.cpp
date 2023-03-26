#include <iostream>
#include <algorithm>
const int MAX = 10001;
int dp[MAX];
int grape[MAX];
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> grape[i];
    }
    dp[0] = 0;
    dp[1] = grape[1];
    dp[2] = grape[1] + grape[2];

    dp[3] = max(dp[2], max(dp[0] + grape[2] + grape[3], dp[1] + grape[3]));

    for (int i = 4; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], max(dp[i - 3] + grape[i - 1] + grape[i], dp[i - 2] + grape[i]));
    }
    cout << dp[n];
    return 0;
}