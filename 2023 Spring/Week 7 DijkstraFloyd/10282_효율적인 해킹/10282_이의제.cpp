#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000

using namespace std;

int t;
int n, d, c;

vector<pair<int, int> > graph[10001];

int dis[10001];

void dijkstra(int s){
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(0, s));

    while(!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_cost = -pq.top().first;
        pq.pop();

        if(cur_cost > dis[cur_node]) continue;

        for(int i = 0; i < graph[cur_node].size(); i++){
            int next_node = graph[cur_node][i].first;
            int next_cost = graph[cur_node][i].second + cur_cost;

            if(next_cost < dis[next_node]) {
                dis[next_node] = next_cost;
                pq.push(make_pair(-next_cost, next_node));
                // cout << next_cost << ", " << next_node << '\n';
            }
        }
    }
}

int main() {
    int cnt = 0, max_node = 0;
    cin >> t;

    for(int k = 0; k < t; k++) {
        cin >> n >> d >> c;

        for(int i = 0; i < 10001; i++)
            graph[i].clear();
            
        for(int i = 0; i < d; i++){
            int v, u, w;
            cin >> v >> u >> w;

            graph[u].push_back(make_pair(v, w));
        }

        fill(dis, dis + 10001, INF);
        dis[c] = 0;
        dijkstra(c);

        cnt = 0;
        max_node = c;
        for(int i = 1; i <= n; i++){
            if(dis[i] != INF) {
                cnt++;
                if(dis[max_node] < dis[i])
                    max_node = i;
            }
        }
        cout << cnt << ' ' << dis[max_node] << '\n';
    }

    return 0;
}