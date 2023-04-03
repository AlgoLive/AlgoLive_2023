#include <iostream>
using namespace std;
int N;
int map[65][65];

int dq(int x, int y, int n)
{
    int flag = map[x][y];

    if (n == 1)
    {
        cout << flag;
        return 0;
    }

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (flag != map[i][j])
            {
                flag = 11;
                break;
            }
        }
    }
    if (flag == 11)
    {
        cout << "(";
        dq(x, y, n / 2);
        dq(x, y + n / 2, n / 2);
        dq(x + n / 2, y, n / 2);
        dq(x + n / 2, y + n / 2, n / 2);
        cout << ")";
    }
    else
    {
        cout << flag;
    }
    return 0;
}

int main()
{
    cin >> N;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }
    dq(0, 0, N);
}