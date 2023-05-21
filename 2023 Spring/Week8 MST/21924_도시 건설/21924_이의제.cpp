#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct KS{
    long from, to, weight;

    KS(long f, long t, long w){
        from = f;
        to = t;
        weight = w;
    }
};


vector<KS> edges;
long parent[100001];

long N, M;
long a, b, c;
long cnt;
long result;

bool comp(KS a, KS b){
    return a.weight < b.weight;
}   

long find(long s){
    if(s == parent[s]) return s;
    else return parent[s] = find(parent[s]);
}

bool Union(long a, long b){
    a = find(a);
    b = find(b);

    if(a == b) return false;
    else {
        parent[a] = b;
        return true;
    }
}

long main() {
    cin >> N >> M;
    for(long i = 1; i <= N; i++)
        parent[i] = i;
    
    for(long i = 0; i < M; i++){
        cin >> a >> b >> c;
        edges.push_back(KS(a, b, c));
        result += c;
    }

    sort(edges.begin(), edges.end(), comp);

    for(long i = 0; i < edges.size(); i++){
        if(Union(find(edges[i].from), find(edges[i].to))){
            result -= edges[i].weight;
            cnt++;
        }
    }
    
    cout << (cnt == N - 1 ? result : -1);

    return 0;
}