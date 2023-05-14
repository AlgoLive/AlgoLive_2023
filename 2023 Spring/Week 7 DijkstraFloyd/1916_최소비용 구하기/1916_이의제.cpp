#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000000000

using namespace std;

int start, finish;
int N, M;
vector<pair<int, int> > graph[1001];
int d[1001];

void dijkstra(int s){
    // pq의 기본은 오름차순
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(0, s));

    while(!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_cost = -pq.top().first;
        pq.pop();

        // cout << cur_node << ", " << cur_cost << '\n';

        if(d[cur_node] < cur_cost) continue;

        for(int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i].first;
            int next_cost = graph[cur_node][i].second + cur_cost;

            if(d[next_node] > next_cost) {
                d[next_node] = next_cost;
                pq.push(make_pair(-next_cost, next_node));
            }
        }
    }
}

int main() {
    cin >> N;
    cin >> M;

    for(int i = 0; i < M; i++){
        int a, b, w;

        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b, w));
    }

    cin >> start >> finish;

    fill(d, d + 1001, INF);
    d[start] = 0;

    dijkstra(start);

    cout << d[finish];

    return 0;
}