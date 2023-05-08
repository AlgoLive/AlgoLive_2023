#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000
using namespace std;
int v, e, s;
int a, b, c;
vector<pair<int, int> > map[20001];
vector<int> dist(20001, INF);

void dijkstra(int start){ // 일반적인 다익스트라
    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push(make_pair(dist[start], start));

    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < cost) // 이미 최단경로를 확인한 노드는 배제
            continue;

        for(int i=0; i<map[now].size(); i++){
            int viacost = cost + map[now][i].first;
            int next = map[now][i].second;

            if(viacost < dist[next]){
                dist[next] = viacost;
                pq.push(make_pair(-viacost, next));
            }
        }

    }
}

int main(){
    cin >> v >> e >> s;
    for(int i=0; i<e; i++){
        cin >> a >> b >> c;
        map[a].push_back(make_pair(c, b));
    }
    
    dijkstra(s);

    for(int i=1; i<=v; i++){
        if(dist[i] == INF)
            cout << "INF" << '\n';
        else 
            cout << dist[i] << '\n';
    }
    return 0;
}