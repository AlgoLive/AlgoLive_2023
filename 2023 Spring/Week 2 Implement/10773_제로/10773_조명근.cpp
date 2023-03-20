#include <iostream>
#include <stack>
using namespace std;
int K;

int main()
{
    stack<int> s;
    cin >> K;
    int ans = 0;
    for (int i = 0; i < K; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp == 0)
        {
            s.pop();
        }
        else
        {
            s.push(tmp);
        }
    }

    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        ans = ans + s.top();
        s.pop();
    }
    cout << ans;
}