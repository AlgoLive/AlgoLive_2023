#include <iostream>
using namespace std;
const int MAX = 2187 + 1;
int map[MAX][MAX];
int ans[3];

int N;

int dq(int a, int b, int n)
{
    if (n == 1)
    {
        if (map[a][b] == -1)
        {
            ans[2]++;
        }
        else
        {
            ans[map[a][b]]++;
        }
        return 0;
    }
    int flag = map[a][b];
    for (int i = a; i < a + n; i++)
    {
        for (int j = b; j < b + n; j++)
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
        for (int i = a; i < a + n; i += n / 3)
        {
            for (int j = b; j < b + n; j += n / 3)
            {
                dq(i, j, n / 3);
            }
        }
    }
    else
    {
        if (flag == -1)
        {
            ans[2]++;
            return 0;
        }
        else
        {

            ans[flag]++;
            return 0;
        }
    }
    return 0;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
    dq(0, 0, N);
    cout << ans[2] << endl;
    cout << ans[0] << endl;
    cout << ans[1] << endl;
}