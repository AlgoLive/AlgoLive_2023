#include <iostream>
#include <cstring>

using namespace std;

int N, M;
bool visited[9];
int q[9];
int front = -1;

void printQ(){
    for(int i = 1; i <= front; i++)
        cout << q[i] << ' ';
    cout << '\n';
}

void DFS(int n, int m){
    visited[n] = true;

    q[++front] = n;

    for(int i = 1; i <= N; i++){
        if(visited[i] == false && m < M) {
            DFS(i, m + 1);
        }
    }

    visited[n] = false;

    if(m >= M)
        printQ();

    front--;
}

int main() {
    memset(visited, false, sizeof(visited));
    cin >> N >> M;

    DFS(0, 0);
    return 0;
}

// 1 2 3 4
// 1 2 4 3
// 1 3 2 4
// 1 3 4 2
// 1 4 2 3
// 1 4 3 2
// 2 1 3 4
// 2 1 4 3
// 2 3 1 4
// 2 3 4 1
// 2 4 1 3
// 2 4 3 1
// 3 1 2 4
// 3 1 4 2
// 3 2 1 4
// 3 2 4 1
// 3 4 1 2
// 3 4 2 1
// 4 1 2 3
// 4 1 3 2
// 4 2 1 3
// 4 2 3 1
// 4 3 1 2
// 4 3 2 1