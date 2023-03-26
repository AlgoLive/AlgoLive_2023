#include <iostream>

using namespace std;
int N;
int ans;

int map[101][101];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < a + 10; j++)
        {
            for (int k = b; k < b + 10; k++)
            {
                if (map[j][k] == 0)
                {
                    ans++;
                    map[j][k] = 1;
                }
            }
        }
    }
    cout << ans;
}