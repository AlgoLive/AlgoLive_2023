#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321;
using namespace std;
int V, E;
int startnode;
vector<pair<int, int>> graph[20001];
int d[20001];

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, startnode));
    d[startnode] = 0;

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
    cin >> V >> E;
    cin >> startnode;
    int to, from, weight;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> weight;
        graph[from].push_back(make_pair(to, weight));
    }
    for (int i = 1; i <= V; i++)
    {
        d[i] = INF;
    }
    dijkstra();
    for (int i = 1; i <= V; i++)
    {
        if (d[i] != 987654321)
        {
            cout << d[i];
            cout << "\n";
        }
        else
        {
            cout << "INF";
            cout << "\n";
        }
    }
}