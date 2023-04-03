#include <iostream>
using namespace std;
long long A, B, C;

long long dq(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
    {
        return A % C;
    }

    if (n % 2 == 0)
    {
        return (dq(n / 2) * dq(n / 2)) % C;
    }
    else
    {
        int tmp = (n - 1) / 2;
        return ((dq(tmp) * dq(tmp) % C) * A % C) % C;
    }
}

int main()
{
    cin >> A >> B >> C;
    cout << dq(B);
}