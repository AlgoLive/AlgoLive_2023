#include <iostream>

using namespace std;

int N;
int map[64][64];

void print(int x, int y, int n){
    bool flag = true;
    int color = map[x][y];

    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            if(color != map[i][j] && flag) {
                int next = n / 2;

                flag = false;

                cout << "(";

                print(x, y, next);
                print(x, y + next, next); 
                print(x + next, y, next);
                print(x + next, y + next, next);

                cout << ")";
            }
        }
    }

    if(flag)
        cout << color;
    else return;
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++){
        string line;
        cin >> line;
        for(int j = 0; j < N; j++){
            map[i][j] = line[j] - '0';
        }
    }

    print(0, 0, N);

    return 0;
}