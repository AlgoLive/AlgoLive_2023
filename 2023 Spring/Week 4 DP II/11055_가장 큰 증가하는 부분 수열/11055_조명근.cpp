#include <iostream>
#include <algorithm>
#include <vector>
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
    dp[0] = arr[0];
    for (int i = 1; i < N; i++)
    {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    vector<int> tmp;
    for (int i = 0; i < N; i++)
    {
        tmp.push_back(dp[i]);
    }
    cout << *max_element(tmp.begin(), tmp.end());
}
