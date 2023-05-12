#include<iostream>

using namespace std;

int n, m, arr[9];
bool vst[9];
void backT(int d){
    if(d == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=0; i<n; i++){
        if(!vst[i]){
            vst[i] = true;
            arr[d] = i+1;
            backT(d+1);
            vst[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    backT(0);

    return 0;
}