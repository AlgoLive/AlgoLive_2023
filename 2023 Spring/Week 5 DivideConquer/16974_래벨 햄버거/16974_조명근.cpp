#include <iostream>
using namespace std;

int N;
long long X;
long long cnt;
long long dpP[51];
long long dpH[51];

long long dq(int n, long long x)
{
    if (n == 0)
    {
        return x;
    }
    if (x == 1)
    {
        return 0;
    }
    else if (x <= 1 + dpH[n - 1])
    {
        return dq(n - 1, x - 1);
    }
    else if (x == 1 + dpH[n - 1] + 1)
    {
        return dpP[n - 1] + 1;
    }
    else if (x <= 1 + dpH[n - 1] + 1 + dpH[n - 1])
    {
        return dpP[n - 1] + 1 + dq(n - 1, x - (1 + dpH[n - 1] + 1));
    }
    else
    {
        return dpP[n - 1] + 1 + dpP[n - 1];
    }
}

int main()
{
    cin >> N >> X;
    dpH[0] = 1;
    dpP[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        dpH[i] = 1 + dpH[i - 1] + 1 + dpH[i - 1] + 1;
        dpP[i] = dpP[i - 1] + 1 + dpP[i - 1];
    }
    cout << dq(N, X);
}