#include <iostream>
using namespace std;
int N, K;
long long dp[201][201];

long long topdown(int x, int y)
{
    if (x == 0 || y == 0)
        return 0;
    if (x == 1)
        return y;
    if (y == 1)
        return 1;
    if (dp[x][y] != 0)
        return dp[x][y];

    long long tmp = (topdown(x, y - 1) + topdown(x - 1, y)) % 1000000000;
    dp[x][y] = tmp;

    return dp[x][y];
}
int main()
{
    cin >> N >> K;
    cout << topdown(N, K);
}

/*
시간초과 난  이유 -> DP를 쓰는데, 방문했을 때 if문을 처리안함. 그래서 연산 늘어나서 시간초과남.
종료조건에 신경쓰자.
*/