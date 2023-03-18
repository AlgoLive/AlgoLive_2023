#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <tuple>

using namespace std;

int N;
int map[20][20];
bool visited[20][20];
int shark = 2;
int eaten = 0;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

struct compare{
	bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
		if(get<2>(a) != get<2>(b)){
            return get<2>(a) > get<2>(b);
        }
        else {
            if(get<0>(a) != get<0>(b)){
                return get<0>(a) > get<0>(b);
            }
            else return get<1>(a) > get<1>(b);
        }
	}
};

tuple<int, int, int> BFS(tuple<int, int, int> start) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, compare > q;

    q.push(start);

    while(!q.empty()){
        tuple<int, int, int> cur = q.top();
        int x = get<0>(cur);
        int y = get<1>(cur);
        q.pop();

        visited[x][y] = true;
        // cout << x << y << get<2>(cur) << '\n';
        if(map[x][y] < shark && map[x][y] != 0) return cur;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if(map[nx][ny] <= shark && visited[nx][ny] == false){
                q.push(make_tuple(nx, ny, get<2>(cur) + 1));
                visited[nx][ny] = true;
            }
        }
    }

    return start;
}

bool isSameLocate(tuple<int, int, int> x, tuple<int, int, int> y){
    return get<0>(x) == get<0>(y) && get<1>(x) == get<1>(y);
}

int main() {
    tuple<int, int, int> prev = make_tuple(-1, -1, 0);
    tuple<int, int, int> shark_locate = prev;
    int result = 0;

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];

            if(map[i][j] == 9) {
                shark_locate = make_tuple(i, j, 0);
                map[i][j] = 0;
            }
        }
    }

    while(true){
        memset(visited, false, sizeof(visited));
        
        shark_locate = BFS(make_tuple(get<0>(shark_locate), get<1>(shark_locate), 0));

        if(!isSameLocate(prev, shark_locate)){
            int temp;
            eaten++;
            temp = map[get<0>(shark_locate)][get<1>(shark_locate)];
            map[get<0>(shark_locate)][get<1>(shark_locate)] = 0;
            result += get<2>(shark_locate);

            if(eaten >= shark){
                eaten = 0;
                shark++;
            }

            prev = shark_locate;

            // for(int i = 0; i < N; i++){
            //     for(int j = 0; j < N; j++){
            //         cout << map[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
            // cout << "ate : " << temp << '\n';
            // cout << "!!!" << get<0>(shark_locate) << "!!!" << get<1>(shark_locate) << '\n';
            // cout << "distance : " << get<2>(shark_locate) << '\n';
            // cout << "result : " << result << '\n';

            // cout << "shark : " << shark << '\n';
            // cout << "eaten : " << eaten << '\n' << '\n';
            // cout << '\n';
        }
        else break;
    }

    cout << result;

    return 0;
}