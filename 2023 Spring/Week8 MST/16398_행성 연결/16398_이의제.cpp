#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct KS {
    int val, from, to;
};

int N;

vector<KS> graph;
int parent[1001];
long long result;

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
    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            KS ks;
            cin >> ks.val;

            if(i >= j) continue;    

            ks.from = i;
            ks.to = j;
            graph.push_back(ks);
        }
    }

    for(int i = 1; i <= N; i++)
        parent[i] = i;

    sort(graph.begin(), graph.end(), comp);

    for(int i = 0; i < graph.size(); i++){
        if(Union(find(graph[i].from), find(graph[i].to)))
            result += graph[i].val;
    }

    cout << result;

    return 0;
}