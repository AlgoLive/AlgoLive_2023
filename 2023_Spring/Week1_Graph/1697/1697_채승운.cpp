#include <iostream>
#include <queue>

using namespace std;
int visited[100001] = { 0, }; // 값으로 시간을 가지고 있다.
int n, k;
queue<int> q; // 점

void BFS(int start){
    q.push(start);
    visited[start] = 0;

    while(!q.empty()){
        int pos = q.front();
        q.pop();

        if(pos == k){ // 도착
            cout << visited[pos]; // 시간 출ㄹ력
            return;
        }

        if(pos + 1 >= 0 && pos + 1 <= 100000){ // 범위 이탈 경우 배제
            if(!visited[pos + 1]){
                visited[pos + 1] = visited[pos] + 1;
                q.push(pos + 1);
            }
        }

        if(pos - 1 >= 0 && pos - 1 <= 100000){
            if(!visited[pos - 1]){
                visited[pos - 1] = visited[pos] + 1;
                q.push(pos - 1);
            }
        }

        if(2 * pos >= 0 && 2 * pos <= 100000){
            if(!visited[2 * pos]){
                visited[2 * pos] = visited[pos] + 1;
                q.push(2 * pos);
            }
        }
    }

}

int main(){    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    BFS(n);
    return 0;
}