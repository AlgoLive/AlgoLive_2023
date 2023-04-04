#include <iostream>

using namespace std;

int N;
int map[128][128];

pair<int, int> operator+(const pair<int, int> & l,const pair<int, int> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
} 

pair<int, int> cnt(int x, int y, int n){
    pair<int, int> answer = make_pair(0, 0);
    bool flag = true;
    int color = map[x][y];

    // cout << "cnt(" << x << " ," << y << " , " << n << ")" << "\n";

    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            if(i == x && j == y) continue;
            if(map[i][j] != color && flag == true){
                answer = cnt(x, y, n / 2) + cnt(x, y + n / 2, n / 2)
                + cnt(x + n / 2, y, n / 2) + cnt(x + n / 2, y + n / 2, n / 2);
                flag = false;
            }
        }
    }

    if(flag)
        (color == 0 ? answer.first: answer.second) += 1;

    return answer;
}

int main() {
    pair<int, int> answer;

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    
    answer = cnt(0, 0, N);
    cout << answer.first << '\n' << answer.second;
    

    return 0;
}