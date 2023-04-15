#include <iostream>
using namespace std;

int n, zero=0, one=0, mone=0;
int paper[2188][2188];

void solve(int x, int y, int size){
    int check = paper[x][y];
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(check != paper[i][j]){
                solve(x, y, size/3);
                solve(x, y+size/3, size/3);
                solve(x, y+2*size/3, size/3);
                solve(x+size/3, y, size/3);
                solve(x+size/3, y+size/3, size/3);
                solve(x+size/3, y+2*size/3, size/3);
                solve(x+2*size/3, y, size/3);
                solve(x+2*size/3, y+size/3, size/3);
                solve(x+2*size/3, y+2*size/3, size/3);
                return;
            }
        }
    }
    if(check == 0){
        zero++;
        return;
    }
    else if(check == 1){
        one++;
        return;
    }
    else{
        mone++;
        return;
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> paper[i][j];
        }
    }
    solve(0, 0, n);
    cout << mone << "\n" << zero << "\n" << one;

    return 0;
}
