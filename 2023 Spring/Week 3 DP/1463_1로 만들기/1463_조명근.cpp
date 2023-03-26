#include <iostream>
#include <algorithm>
using namespace std;
int d[1000001];

int top_down(int n)
{
    if (n == 1)
        return 0;
    if (d[n] > 0)
        return d[n];
    d[n] = top_down(n - 1) + 1;
    if (n % 2 == 0)
    {
        int temp = top_down(n / 2) + 1;
        if (d[n] > temp)
            d[n] = temp;
    }
    if (n % 3 == 0)
    {
        int temp = top_down(n / 3) + 1;
        if (d[n] > temp)
            d[n] = temp;
    }
    return d[n];
}
int main()
{
    int n;
    cin >> n;
    cout << top_down(n);
}