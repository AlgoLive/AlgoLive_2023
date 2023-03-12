#include <iostream>
#include <queue>

const int MAX = 100001;
int N, K;
int cnt;
using namespace std;
bool visited[MAX];
int map[MAX];

void bfs()
{
    queue<int> q;
    q.push(N);
    visited[N] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == K)
        {
            break;
        }
        for (int i = 0; i < 3; i++)
        {
            int nx;
            if (i == 0)
            {
                nx = cur - 1;
            }
            else if (i == 1)
            {
                nx = cur + 1;
            }
            else if (i == 2)
            {
                nx = cur * 2;
            }

            if (nx >= MAX || nx < 0)
            {
                continue;
            }
            if (!visited[nx])
            {
                visited[nx] = true;
                q.push(nx);
                map[nx] = map[cur] + 1;
            }
        }
    }
}

int main()
{
    cin >> N >> K;
    bfs();
    cout << map[K];
}

// 범위 설정을 잘하자.. 제발..