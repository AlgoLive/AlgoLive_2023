#include <iostream>
#include <vector>
#include <algorithm>

#define pi pair<char, pair<int, int> >
using namespace std;
int parent[1001];
int n, m, k;
vector<pi> v;

int Find(int num){
    if(num == parent[num])
        return num;
    return parent[num] = Find(parent[num]);
}

bool Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a == b) return false;
    else {
        parent[a] = b;
        return true;
    }
}

bool REDfirst(pi a, pi b){ // 빨강 우선 트리
    return a.first > b.first;
}

bool BLUEfirst(pi a, pi b){ // 파랑 우선 트리
    return a.first < b.first;
}

int MST(int n){
    int cnt = 0;
    for(int i=1; i<=n; i++) 
        parent[i] = i;

    for(int i=0; i<v.size(); i++){
        int a = v[i].second.first;
        int b = v[i].second.second;
        if(Union(a, b)){
            if(v[i].first == 'B') cnt++; // 총 블루의 개수 세어 반환
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(1){
        cin >> n >> m >> k;
        if(n == 0 && m == 0 && k == 0) break; // 종료조건

        int f, t;
        char c;
        for(int i=0; i<m; i++){
            cin >> c;
            cin >> f >> t;
            v.push_back(make_pair(c, make_pair(f, t)));
        }

        sort(v.begin(), v.end(), REDfirst); // 빨강 우선일 때 개수
        int range1 = MST(n);

        sort(v.begin(), v.end(), BLUEfirst); // 블루 우선일 때 개수
        int range2 = MST(n);

        if(k >= range1 && k <= range2){ // 사이에 k가 존재하면 가능
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
        v.clear();
    }

    return 0;
}