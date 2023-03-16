#include <iostream>
#include <string>

using namespace std;

int cnt[10];

int max(int a, int b)
{
    return a > b ? a : b;
}

int round(int a, int b)
{
    if (a % 2 == 0)
    {
        return a / b;
    }
    else
    {
        return a / b + 1;
    }
}

int main()
{
    string line;
    int _max;

    cin >> line;

    for (int i = 0; i < line.size(); i++)
    {
        cnt[line[i] - '0']++;
    }

    _max = cnt[0];
    for (int i = 0; i < 10; i++)
    {
        if (i == 6 || i == 9)
            continue;
        if (cnt[i] > _max)
            _max = cnt[i];
    }

    cout << max(_max, round(cnt[6] + cnt[9], 2));

    return 0;
}