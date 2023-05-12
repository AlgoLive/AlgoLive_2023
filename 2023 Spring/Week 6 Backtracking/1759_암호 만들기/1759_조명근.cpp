#include <iostream>
#include <algorithm>
using namespace std;
int visited[16];
char arr[16];
char res[16];
int L, C;

void backtrack(int n)
{
    if (n == L)
    {
        int cnt = 0;
        int cnta = 0;
        for (int i = 0; i < n; i++)
        {
            if (res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u')
            {
                cnt++;
            }
            else
            {
                cnta++;
            }
        }
        if (cnt == 0 || cnta < 2)
        {
            return;
        }
        for (int i = 0; i < n; i++)
        {
            cout << res[i];
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < C; i++)
    {
        if (!visited[i])
        {
            for (int j = 0; j <= i; j++)
            {
                visited[j] = true;
            }
            res[n] = arr[i];
            backtrack(n + 1);
            for (int j = 0; j <= i; j++)
            {
                visited[j] = false;
            }
        }
    }
}

int main()
{
    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + C);
    backtrack(0);
}