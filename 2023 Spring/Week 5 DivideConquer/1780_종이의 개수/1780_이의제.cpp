#include <iostream>

using namespace std;

int N;
int map[2500][2500];
int answer[3];

void cnt(int x, int y, int n){
    bool flag = true;
    int color = map[x][y];

    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            if(map[i][j] != color && flag){
                int next = n / 3;
                flag = false;
                cnt(x, y, next);
                cnt(x, y + next, next);
                cnt(x, y + next * 2, next);
                cnt(x + next, y, next);
                cnt(x + next, y + next, next);
                cnt(x + next, y + next * 2, next);
                cnt(x + next * 2, y, next);
                cnt(x + next * 2, y + next, next);
                cnt(x + next * 2, y + next * 2, next);
            }
        }
    }
    if(flag)
        answer[color == -1 ? 0 : (color == 0 ? 1 : 2)]++;
    else return;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    cnt(0, 0, N);

    cout << answer[0] << '\n' << answer[1] << '\n' << answer[2];

    return 0;
}