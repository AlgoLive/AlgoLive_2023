#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int a, b, c;
int ans1, ans2;
int parent[1001];

struct KS { // 간선
    int from, to, up; // 출발지, 도착지, 내리막여부
};

vector<KS> Edges; // 간선들

bool cmp1(KS k1, KS k2){ // 오르막길부터 정렬
    return k1.up < k2.up;
}

bool cmp2(KS k1, KS k2){ // 내리막길부터 정렬
    return k1.up > k2.up;
}

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<=n; i++){
        parent[i] = i;
    }

    KS ks1;
    cin >> ks1.from >> ks1.to >> ks1.up; // 0-1 경로는 오르막/내리막 여부 상관업이 시작할때 반드시 포함해야함
    Edges.push_back(ks1);

    for(int i=0; i<m; i++){
        KS ks;
        cin >> ks.from >> ks.to >> ks.up;
        Edges.push_back(ks);
    }

    sort(Edges.begin() + 1, Edges.end(), cmp1); // 오르막 선 정렬
    for(int i=0; i<m; i++){
        int f = find(Edges[i].from);
        int t = find(Edges[i].to);

        if(f != t){
            Union(f, t);
            if(Edges[i].up == 0) // 오르막길 개수 세기
                ans1 += 1;
        }
    }

    for(int i=0; i<=n; i++){
        parent[i] = i;
    } // 다시 부모 초기화

    sort(Edges.begin() + 1, Edges.end(), cmp2); // 내리막 선 정렬
    for(int i=0; i<m; i++){
        int f = find(Edges[i].from);
        int t = find(Edges[i].to);

        if(f != t){
            Union(f, t);
            if(Edges[i].up == 0)
                ans2 += 1;
        }
    }

    cout << ans1*ans1 - ans2*ans2 << '\n';
    return 0;
}