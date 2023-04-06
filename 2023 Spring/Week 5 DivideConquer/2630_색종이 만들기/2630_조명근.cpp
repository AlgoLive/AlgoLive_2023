#include <iostream>
using namespace std;
int white, blue;
int map[129][129];

int d_q(int x, int y, int n)
{
    int countw = 0;

    int countb = 0;
    int total = n * n;

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (map[i][j] == 0)
            {
                countw++;
            }
            else if (map[i][j] == 1)
            {
                countb++;
            }
        }
    }
    if (countw == total)
    {
        white++;
        return 0;
    }
    if (countb == total)
    {
        blue++;
        return 0;
    }
    for (int i = x; i < x + n; i += n / 2)
    {
        for (int j = y; j < y + n; j += n / 2)
        {
            d_q(i, j, n / 2);
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    d_q(0, 0, n);
    cout << white << endl;
    cout << blue;
}