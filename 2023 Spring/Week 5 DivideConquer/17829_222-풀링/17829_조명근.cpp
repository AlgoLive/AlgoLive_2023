#include <iostream>
#include <algorithm>
#include <vector>
const int MAX = 1025;
int n;
int map[MAX][MAX];
using namespace std;

int d_q(int x, int y)
{
    vector<int> a;
    for (int i = x; i < x + 2; i++)
    {
        for (int j = y; j < y + 2; j++)
        {
            a.push_back(map[i][j]);
        }
    }
    sort(a.begin(), a.end());
    return a[a.size() - 2];
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    while (n > 1)
    {
        for (int i = 0; i < n; i += 2)
        {
            for (int j = 0; j < n; j += 2)
            {
                map[i / 2][j / 2] = d_q(i, j);
            }
        }
        n /= 2;
    }
    cout << map[0][0];
}