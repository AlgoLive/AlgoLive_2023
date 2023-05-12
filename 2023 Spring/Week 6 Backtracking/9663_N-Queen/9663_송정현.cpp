#include <iostream>
using namespace std;

int n, res = 0;
int map[16];

bool isPos(int cnt){
    for(int i=0; i<cnt; i++){
        if(map[i] == map[cnt] || abs(map[i] - map[cnt]) == abs(i - cnt))    return false;
    }
    return true;
}
void backT(int cnt){
    if(cnt == n){
        res++;
        return;
    }
    for(int i=0; i<n; i++){
        map[cnt] = i;
        if(isPos(cnt)){
            backT(cnt+1);
        }
    }
}
int main(){
    cin >> n;
    backT(0);
    cout << res;

    return 0;
}
