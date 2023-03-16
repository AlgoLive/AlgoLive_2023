#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool map[100001];

int BFS(int start, int end){
    queue<pair<int, int> > q;

    q.push(make_pair(start, 0));

    while(!q.empty()){
        int location = q.front().first;
        int time = q.front().second;

        q.pop();
        map[location] = true;
        // cout << location << time << '\n';    

        if(location == end) return time;

        if(location * 2 - end <= end - location && location * 2 <= 100000 && !map[location * 2]) q.push(make_pair(location * 2, time + 1));
        if(location + 1 <= end && !map[location + 1]) q.push(make_pair(location + 1, time + 1));
        if(location - 1 <= end && location - 1 >= 0 && !map[location - 1]) q.push(make_pair(location - 1, time + 1));
    }
    return -1;
}

int main() {
    int N, K;
    cin >> N >> K;
    memset(map, false, sizeof(map));

    if(N >= K)
        cout << N - K;
    else {
        cout << BFS(N, K);
    }
    return 0;
}