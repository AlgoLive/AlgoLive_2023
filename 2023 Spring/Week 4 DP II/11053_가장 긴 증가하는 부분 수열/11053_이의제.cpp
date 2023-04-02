#include <iostream>
#include <algorithm>
using namespace std;
int N;
int num[1001];
int dp[1001];
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    dp[0] = 1;
    for (int i = 1; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (num[i] < num[j])
            {
                continue;
            }
            else
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cout << dp[i] << ' ';
        tmp = dp[i];
        if (tmp < dp[i])
        {
            tmp = dp[i];
        }
    }
    cout << tmp;
}