#include <iostream>

using namespace std;

int N;
char map[6561][6561];

void print(int x, int y, int n){
    int next = n / 3;
    if(n == 3){
        for(int i = x; i < x + 3; i++){
            for(int j = y; j < y + 3; j++){
                if(i == x + 1 && j == y + 1)
                    map[i][j] = ' ';
                else
                    map[i][j] = '*';
            }
        }
    }
    else {
        print(x, y, next);
        print(x, y + next, next);
        print(x, y + 2 * next, next);
        print(x + next, y, next);
        for(int i = x + next; i < x + 2 * next; i++){
            for(int j = y + next; j < y + 2 * next; j++){
                map[i][j] = ' ';
            }
        }
        print(x + next, y + 2 * next, next);
        print(x + 2 * next, y, next);
        print(x + 2 * next, y + next, next);
        print(x + 2 * next, y + 2 * next, next);
    }
}

int main() {
    cin >> N;

    print(0, 0, N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << map[i][j];
        }
        cout << '\n';
    }
    return 0;
}