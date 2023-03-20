#include <iostream>
#include <string>
using namespace std;
const int MAX = 1000001;
int N;
int lst[10];
int ans;

int main()
{
    string a;
    cin >> a;
    int temp;
    for (int i = 0; i < a.size(); i++)
    {
        temp = a[i] - '0';
        lst[temp] += 1;
    }
    int sum = lst[6] + lst[9];

    if (sum % 2 == 0)
    {
        lst[6] = sum / 2;
        lst[9] = sum / 2;
    }
    else
    {
        lst[6] = ((sum - 1) / 2) + 1;
        lst[9] = ((sum - 1) / 2) + 1;
    }

    for (int i = 0; i < 10; i++)
    {
        if (lst[i] > ans)
        {
            ans = lst[i];
        }
    }
    cout << ans;
    return 0;
}