#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[1024][1024];

void pulling(int n) {
    if(n == 1) return;

    for(int i = 0; i < n; i += 2){
        for(int j = 0; j < n; j += 2){
            vector<int> list;
            list.push_back(map[i][j]);
            list.push_back(map[i][j + 1]);
            list.push_back(map[i + 1][j]);
            list.push_back(map[i + 1][j + 1]);
            sort(list.begin(), list.end());

            map[i / 2][j / 2] = list[2];
        }
    }

    pulling(n / 2);
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    pulling(N);

    cout << map[0][0];

    return 0;
}