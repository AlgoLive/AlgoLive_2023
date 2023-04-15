#include <iostream>
using namespace std;

int n;
char map[6562][6562];

void solve(int x, int y, int n){
    if(n == 3){
        map[x+1][y+1] = ' ';
    }
    else{
        for(int i=x+n/3; i<x+2*n/3; i++){
            for(int j=y+n/3; j<y+2*n/3; j++){
                map[i][j] = ' ';
            }
        }
        solve(x, y, n/3);
        solve(x, y+n/3, n/3);
        solve(x, y+2*n/3, n/3);
        solve(x+n/3, y, n/3);
        solve(x+n/3, y+2*n/3, n/3);
        solve(x+2*n/3, y, n/3);
        solve(x+2*n/3, y+n/3, n/3);
        solve(x+2*n/3, y+2*n/3, n/3);
        return;
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            map[i][j] = '*';
        }
    }
    solve(0, 0, n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j];
        }
        cout << "\n";
    }
    return 0;
}
