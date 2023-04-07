#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int mem[1000001];
int N;

int dp(int n)
{
    int result = 0;
    if (n == 1)
    {
        // cout << 1 << '\n';
        return 0;
    }
    if (n == 2)
    {
        // cout << 2 << '\n';
        return 1;
    }
    if (n == 3)
    {
        // cout << 3 << '\n';
        return 1;
    }

    // cout << n << '\n';
    if(mem[n] != 0) return mem[n];

    if (n % 3 == 0 && n % 2 == 0) {
        if(mem[n] == 0)
            mem[n] = min(min(dp(n / 3) + 1, dp(n / 2) + 1), dp(n - 1) + 1);
        return mem[n];
    }
    if (n % 3 == 0){
        if(mem[n] == 0)
            mem[n] = min(dp(n / 3) + 1, dp(n - 1) + 1);
        return mem[n];
    }
    if (n % 2 == 0){
        if(mem[n] == 0)
            mem[n] = min(dp(n / 2) + 1, dp(n - 1) + 1);
        return mem[n];
    }

    mem[n] = dp(n - 1) + 1;
    return mem[n];
}

int main()
{
    memset(mem, 0, sizeof(mem));
    cin >> N;

    mem[1] = 0;
    mem[2] = 1;
    mem[3] = 1;
    //

    // for(int i = 4; i < N; i++){
    //     if
    // }

    cout << dp(N);

    return 0;
}

// 2 - 1 => 1
// 3 / 3 => 1
// 4 - 1 / 3 or 4 / 2 / 2 => 2

// 5 - 1 = 4 => 1 + dp[4]

// 6 / 3 / 2 => 2

// 7 - 1 = 6 => 1 + dp[6]

// 8 / 2 / 2 / 2 => 3
// 9 / 3 / 3 => 2

// 10 - 1 = 9 => 1 + dp[9]

// 11 - 1 = 10 => 1 + dp[10]

// 12 / 3 / 2 / 2 => 3