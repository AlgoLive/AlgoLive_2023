#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
int N, M;
int d[1001];
int startnode, endnode;
vector<pair<int, int>> graph[1001];
void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    d[start] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (d[now] < dist)
        {
            continue;
        }
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i].first;
            int ncost = dist + graph[now][i].second;
            if (ncost < d[next])
            {
                d[next] = ncost;
                pq.push(make_pair(-ncost, next));
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    int from, to, cost;
    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }
    cin >> startnode >> endnode;
    for (int i = 1; i <= N; i++)
    {
        d[i] = INF;
    }
    dijkstra(startnode);
    cout << d[endnode];
}