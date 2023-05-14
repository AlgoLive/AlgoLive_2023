#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int n, m, st, dest;
vector<pair<int, int>> v[1001]; // <도착, 비용>
vector<int> dist(1001, INF);

void Dijkstra(int start){
    priority_queue<pair<int, int>> pq; // <비용, 도착>
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] < cost)    continue;
        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i].first;
            int nCost = cost + v[cur][i].second;
            if(nCost < dist[next]){
                dist[next] = nCost;
                pq.push({-nCost, next});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    cin >> st >> dest;
    Dijkstra(st);
    cout << dist[dest];

    return 0;
}
