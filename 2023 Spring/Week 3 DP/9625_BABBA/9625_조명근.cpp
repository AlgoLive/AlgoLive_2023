#include <iostream>
using namespace std;

int dpA[46];
int dpB[46];

int main()
{
    int n;
    cin >> n;
    dpA[1] = 0;
    dpB[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dpA[i] = dpB[i - 1];
        dpB[i] = dpB[i - 1] + dpA[i - 1];
    }
    cout << dpA[n] << " " << dpB[n];
}