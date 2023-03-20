#include <iostream>
#include <algorithm>
using namespace std;

int set=0, vis[10], cnt=0;
string s;


int main(){
    cin >> s;
    int size = s.size();

    for(int i=0; i<size; i++){
        int k = s[i]-'0';
        if(k == 6 || k == 9){
            cnt++;
            continue;
        }
        vis[k]++;
    }
    for(int i=0; i<10; i++){
        if(set < vis[i]){
            set = vis[i];
        }
    }
    if(cnt % 2 == 0){
        cnt /= 2;
    }
    else{
        cnt = (cnt+1)/2;
    }

    cout << max(set, cnt);
    return 0;
}
