#include <iostream>
#define MAXNUM 100000000
using namespace std;
int minres = MAXNUM;
int maxres = -MAXNUM;
int N;
int arr[12];
int calc[4];

void backtrack(int result, int count)
{
    if (count == N - 1)
    {
        if (minres > result)
        {
            minres = result;
        }
        if (maxres < result)
        {
            maxres = result;
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (calc[i] == 0)
        {
            continue;
        }
        calc[i]--;
        if (i == 0)
        {
            backtrack(result + arr[count + 1], count + 1);
        }
        else if (i == 1)
        {
            backtrack(result - arr[count + 1], count + 1);
        }
        else if (i == 2)
        {
            backtrack(result * arr[count + 1], count + 1);
        }
        else if (i == 3)
        {
            backtrack(result / arr[count + 1], count + 1);
        }
        calc[i]++;
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> calc[i];
    }
    backtrack(arr[0], 0);
    cout << maxres << endl;
    cout << minres << endl;
}