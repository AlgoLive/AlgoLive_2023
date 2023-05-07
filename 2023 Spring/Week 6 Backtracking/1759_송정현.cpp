#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<char> v;
vector<char> res;

void backT(int len){
    if(res.size() == n){
        int vowel = 0;
        for(int i=0; i<n; i++) {
            if (res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u') {
                vowel++;
            }
        }
        if(vowel >= 1 && n-vowel >= 2){
            for(int i=0; i<n; i++){
                cout << res[i];
            }
            cout << "\n";
            return;
        }
    }
    for(int i=len; i<m; i++){
        res.push_back(v[i]);
        backT(i+1);
        res.pop_back();
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        char a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    backT(0);
    return 0;
}
