#include <iostream>

using namespace std;
int n;
int res[3] = { 0, };
int map[2188][2188];

bool colorcheck(int r, int c, int a){ // 시작점 r, c에서 n * n 영역이 모두 같은 색인지 확인
    int color = map[r][c];
    for(int i=r; i<r+a; i++){
        for(int j=c; j<c+a; j++){
            if(map[i][j] != color) return false;
        }
    }
    return true;
}

void qt(int r, int c, int n){
    if(colorcheck(r, c, n)){
        if(map[r][c] == -1) res[0]++;
        else if(map[r][c] == 0) res[1]++;
        else res[2]++;
    } else {
        n /= 3; // 색종이 만들기 문제와 동일한 패턴

        qt(r, c, n);
        qt(r, c + n, n);
        qt(r, c + 2 * n, n);
        qt(r + n, c, n);    
        qt(r + n, c + n, n);
        qt(r + n, c + 2 * n, n);
        qt(r + 2 * n, c, n);        
        qt(r + 2 * n, c + n, n);            
        qt(r + 2 * n, c + 2 * n, n);            
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    qt(0, 0, n);
    cout << res[0] << '\n'; // -1로 채워진 종이의 개수
    cout << res[1] << '\n'; // 0
    cout << res[2] << '\n'; // 1
    return 0;
}