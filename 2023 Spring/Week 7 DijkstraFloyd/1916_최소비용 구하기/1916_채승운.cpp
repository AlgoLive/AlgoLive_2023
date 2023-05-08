#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
using namespace std;
int n, m;
int start, e;
vector<pair<int, int> > map[1001];
vector<int> dist(1001, INF);

void dijkstra(int start){
    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push(make_pair(-dist[start], start));

    while(!pq.empty()){
        int nowcost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < nowcost)
            continue;

        for(int i=0; i < map[now].size(); i++){
            int next = map[now][i].second;
            int nextcost = map[now][i].first + nowcost;

            if(nextcost < dist[next]){
                dist[next] = nextcost;
                pq.push(make_pair(-nextcost, next));
            }
        }
    }
}

int main(){
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back(make_pair(c, b));
    }

    cin >> start >> e;
    dijkstra(start);
    cout << dist[e] << '\n';
    return 0;
}