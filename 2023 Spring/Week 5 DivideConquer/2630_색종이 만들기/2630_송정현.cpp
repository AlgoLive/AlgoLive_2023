#include <iostream>
using namespace std;

int n, blue=0, white=0;
int paper[129][129];

void solve(int x, int y, int size){
    int check = paper[x][y];    // 기준 정하기
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(check != paper[i][j]){   // 모두 같은 색이 아니면
                solve(x, y, size/2);
                solve(x, y+size/2, size/2);
                solve(x+size/2, y, size/2);
                solve(x+size/2, y+size/2, size/2);
                return;
            }
        }
    }
    if(check == 0)  white++;
    else    blue++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> paper[i][j];
        }
    }
    solve(0, 0, n);
    cout << white << "\n" << blue;

    return 0;
}
/**
 * 1. 한 사분면이 모두 같은 색인지 확인
 * 2. 아니라면 4개로 나눔 / 맞으면 색상 카운트
 * 2사분면 : (x, y, n/2)
 * 1사분면 : (x, y+n/2, n/2)
 * 3사분면 : (x+n/2, y, n/2)
 * 4사분면 : (x+n/2, y+n/2, n/2)
*/