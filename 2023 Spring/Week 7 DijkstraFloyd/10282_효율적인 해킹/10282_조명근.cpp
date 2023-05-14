#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
vector<pair<int, int>> graph[10001];
int V, E, T, SNODE;
int d[10001];

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(SNODE, 0));
    d[SNODE] = 0;
    while (!pq.empty())
    {
        int cur = pq.top().first;
        int dist = -pq.top().second;
        pq.pop();
        if (dist > d[cur])
        {
            continue;
        }
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int ndist = dist + graph[cur][i].second;
            int next = graph[cur][i].first;
            if (ndist < d[next])
            {
                d[next] = ndist;
                pq.push(make_pair(next, -ndist));
            }
        }
    }
}

int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        memset(d, 0, 10001);
        cin >> V >> E >> SNODE;
        for (int j = 0; j < E; j++)
        {
            int from, to, weight;
            cin >> to >> from >> weight;
            graph[from].push_back(make_pair(to, weight));
        }
        for (int j = 0; j <= V; j++)
        {
            d[j] = INF;
        }
        dijkstra();
        int infectcnt = 0;
        int ans = 0;
        for (int j = 1; j <= V; j++)
        {
            if (d[j] != INF)
            {
                infectcnt++;
                ans = max(ans, d[j]);
            }
        }
        cout << infectcnt << " " << ans << "\n";
        for (int j = 0; j <= V; j++)
        {
            int Size = graph[j].size();
            for (int k = 0; k < Size; k++)
            {
                graph[j].pop_back();
            }
        }
    }
}
