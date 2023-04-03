#include <iostream>

using namespace std;
int n;
int map[129][129];

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
        if(map[r][c] == 0) cout << '0';
        else cout << '1';
    } else {
        n = n / 2;

        cout << '('; // 시작과 끝에 괄호를 달은 것 빼면 색종이 만들기와 동일
        qt(r, c, n);
        qt(r, c + n, n);
        qt(r + n, c, n);
        qt(r + n, c + n, n);
        cout << ')';
    }
}

int main(){

    cin >> n;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<n; j++){
            map[i][j] = str[j] - '0';
        }
    }

    qt(0, 0, n);
    return 0;
}