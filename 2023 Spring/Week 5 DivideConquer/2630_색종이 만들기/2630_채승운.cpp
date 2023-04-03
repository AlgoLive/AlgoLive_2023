#include <iostream>

using namespace std;
int n;
int map[129][129];
int res[2] = { 0, };

bool colorcheck(int r, int c, int a){ // 시작점 r, c에서 n * n 영역이 모두 같은 색인지 확인
    int color = map[r][c];
    for(int i=r; i<r+a; i++){
        for(int j=c; j<c+a; j++){
            if(map[i][j] != color) return false;
        }
    }
    return true;
}

void cp(int r, int c, int n){ // 전역변수 말고 인자로 안전하게 상황 가져가기
    if(colorcheck(r, c, n)){ 
        if(map[r][c] == 0) res[0]++;
        else res[1]++;
        return;
    }

    n = n / 2;
    cp(r, c, n);
    cp(r, c + n, n);
    cp(r + n, c, n);
    cp(r + n, c + n, n);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    cp(0, 0, n);
    cout << res[0] << '\n';
    cout << res[1] << '\n';
    return 0;
}