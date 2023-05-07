#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v[2001];
bool visited[2001];
bool answer = false;

void dfs(int node, int depth)
{
    if (depth == 4)
    {
        answer = true;
        return;
    }
    visited[node] = true;
    for (int i = 0; i < v[node].size(); i++)
    {
        int next = v[node][i];
        if (!visited[next] && !answer)
        {
            dfs(next, depth + 1);
        }
    }
    visited[node] = false;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < N; i++)
    {
        dfs(i, 0);
        if (answer)
        {
            break;
        }
    }

    cout << answer;
    return 0;
}