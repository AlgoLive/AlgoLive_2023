#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b;
vector<int> v[2001];
bool vis[2001];
bool ans;

void backT(int depth, int node){
    if(depth == 4){
        ans = true;
        return;
    }
    vis[node] = true;
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(!vis[next] && !ans){
            backT(depth+1, next);
        }
    }
    vis[node] = false;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0; i<n; i++){
        backT(0, i);
        if(ans) break;
    }
    cout << ans;

    return 0;
}
