#include <iostream>
#include <cstring>
using namespace std;
int N;
// 억까의 원인 3^7 + 1
const int MAX = 6562;
char map[MAX][MAX];

int dq(int n, int x, int y)
{
    if (n == 3)
    {
        for (int i = x; i < x + 3; i++)
        {
            for (int j = y; j < y + 3; j++)
            {
                if ((i == (x + 1)) && (j == (y + 1)))
                {
                    map[i][j] = ' ';
                }
                else
                {
                    map[i][j] = '*';
                }
            }
        }

        return 0;
    }
    else
    {
        for (int i = x; i < x + n; i += n / 3)
        {
            for (int j = y; j < y + n; j += n / 3)
            {
                if ((i == (x + n / 3)) && (j == (y + n / 3)))
                {
                    continue;
                }
                else
                {
                    dq(n / 3, i, j);
                }
            }
        }
    }
    return 0;
}

int main()
{
    cin >> N;
    memset(map, ' ', sizeof(map));
    dq(N, 0, 0);
    // print

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}