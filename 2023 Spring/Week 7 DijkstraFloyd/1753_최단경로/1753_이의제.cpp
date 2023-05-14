#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000

using namespace std;

int V, E;
int start;
vector<pair<int, int> > list[20001];
int d[20001];

void dijsktra(int s){
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(0, s));

    while(!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_cost = -pq.top().first;
        pq.pop();

        if(cur_cost > d[cur_node]) continue;

        for(int i = 0; i < list[cur_node].size(); i++){
            int next_node = list[cur_node][i].first;
            int next_cost = list[cur_node][i].second + cur_cost;

            if(d[next_node] > next_cost){
                d[next_node] = next_cost;
                pq.push(make_pair(-next_cost, next_node));
            }
        }
    }
}

int main() {
    int u, v, w;

    cin >> V >> E;
    cin >> start;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        list[u].push_back(make_pair(v, w));
    }

    fill(d, d + 20001, INF);
    d[start] = 0;
    dijsktra(start);

    for(int i = 1; i <= V; i++){
        cout << (d[i] == INF ? "INF" : to_string(d[i])) << '\n';
    }

    return 0;
}