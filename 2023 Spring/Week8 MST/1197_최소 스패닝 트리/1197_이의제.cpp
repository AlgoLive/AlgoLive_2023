#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct KS {
    int weight, from, to;

    KS(int w, int f, int t) {
        weight = w;
        from = f;
        to = t;
    }
};

bool comp(KS a, KS b) {
    return a.weight < b.weight;
}

vector<KS> edges;
int parent[10001];

int V, E;
int A, B, C;
int result;

int find(int num) {
    if(num == parent[num]) return num;

    return parent[num] = find(parent[num]);
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);

    if(a == b) return false;
    else {
        parent[a] = b;
        return true;
    }
}

int main() {
    cin >> V >> E;
    for(int i = 1; i <= V; i++)
        parent[i] = i;

    for(int i = 0; i < E; i++){
        cin >> A >> B >> C;
        edges.push_back(KS(C, A, B));
    }

    sort(edges.begin(), edges.end(), comp);

    for(int i = 0; i < E; i++) {
        if(Union(find(edges[i].from), find(edges[i].to)))
            result += edges[i].weight;
    }

    cout << result;

    return 0;
}