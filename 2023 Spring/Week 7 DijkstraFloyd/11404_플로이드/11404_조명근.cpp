#include <iostream>
#include <algorithm>
using namespace std;
int info[101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int m;
    cin >> m;

    fill(info[0], info[101], 987654321);

    for (int i = 1; i <= n; i++)
    {
        info[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        info[from][to] = min(info[from][to], cost);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                info[i][j] = min(info[i][j], info[i][k] + info[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (info[i][j] == 987654321)
                cout << "0 ";
            else
                cout << info[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}