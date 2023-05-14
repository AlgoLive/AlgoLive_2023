#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int T;
int dist[10001];

void Dijkstra(vector<pair<int, int>> v[], int start, int N){
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
    int cnt=0, time=0;
    for(int i=1; i<=N; i++){
        if(dist[i] != INF){
            cnt++;
            time = max(time, dist[i]);
        }
    }
    cout << cnt << " " << time << "\n";
}

int main(){
    cin >> T;
    while(T--){
        vector<pair<int, int>> v[10001]; // <도착, 비용>
        int n, d, c;
        cin >> n >> d >> c;
        for(int i=0; i<d; i++){
            int a, b, s;
            cin >> a >> b >> s;
            v[b].push_back({a, s});
        }
        fill_n(dist, 10001, INF);
        Dijkstra(v, c, n);

    }

    return 0;
}
