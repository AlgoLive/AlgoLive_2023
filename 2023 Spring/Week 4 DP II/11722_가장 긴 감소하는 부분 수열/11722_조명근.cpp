#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[1001];
int dp[1001];
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int res = 1;
    dp[0] = 1;
    for (int i = 1; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(dp[i], res);
    }
    cout << res << endl;
}