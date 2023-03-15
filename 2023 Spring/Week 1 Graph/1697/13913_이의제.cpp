#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[100001];

int BFS(int start, int end){
    queue<pair<int, int> > q;

    q.push(make_pair(start, 0));

    while(!q.empty()){
        int location = q.front().first;
        int time = q.front().second;

        q.pop();
        // cout << location << time << '\n';

        if(location == end)
            return time;

        if(location * 2 - end <= end - location && location * 2 <= 100000 && !map[location * 2]){
            q.push(make_pair(location * 2, time + 1));
            map[location * 2] = 1;
        }
        if(location + 1 <= end && !map[location + 1]) {
            q.push(make_pair(location + 1, time + 1));
            map[location + 1] = 2;
        }
        if(location - 1 <= end && location - 1 >= 0 && !map[location - 1]) {
            q.push(make_pair(location - 1, time + 1));
            map[location - 1] = 3;
        }
    }
    return -1;
}

int cal(int num){
    int result;
    if(map[num] == 1)
        result = num / 2;
    else if(map[num] == 2)
        result = num - 1;
    else if(map[num] == 3)
        result = num + 1;
    else
        result = -1;
    return result;
}

int main() {
    int N, K;
    int path[100000];
    int cnt = 1;
    cin >> N >> K;
    memset(map, false, sizeof(map));

    if(N >= K){
        cout << N - K << '\n';
        for(int i = N; i != K; i--){
            cout << i << ' ';
        }
        cout << K;
    }
    else {
        cnt = BFS(N, K);
        cout << cnt << '\n';
        for(int i = K, j = cnt; i != N && j >= 0; i = cal(i), j--){
            path[j] = i;
        }
        cout << N << ' ';
        for(int i = 1; i < cnt; i++)
            cout << path[i] << ' ';
        cout << K;
    }
    return 0;
}