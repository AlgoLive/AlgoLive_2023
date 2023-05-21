#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct KS {
    int val, from, to;
};

int N, M;

vector<KS> graph;
int parent[100001];
int result, maxVal;

bool comp(KS a, KS b){
    return a.val < b.val;
}

int find(int num){
    if(num == parent[num]) return num;

    return parent[num] = find(parent[num]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return false;
    else {
        parent[a] = b;
        return true;
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        KS ks;
        cin >> ks.from >> ks.to >> ks.val;
        graph.push_back(ks);
    }

    for(int i = 1; i <= N; i++)
        parent[i] = i;

    sort(graph.begin(), graph.end(), comp);

    for(int i = 0; i < M; i++) {
        if(Union(find(graph[i].from), find(graph[i].to))){
            result += graph[i].val;
            maxVal = max(maxVal, graph[i].val);
        }
    }

    cout << result - maxVal;

    return 0;
}