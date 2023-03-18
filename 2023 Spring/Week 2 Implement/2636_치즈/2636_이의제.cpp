#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int map[101][101];
bool visited[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0 ,0 ,1, -1 };

void DFS(pair<int, int> start) {
	int x = start.first;
	int y = start.second;

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

		if (map[nx][ny] == 0 && visited[nx][ny] == false) {
			DFS(make_pair(nx, ny));
		}
	}
}

int main() {
	int result = 0;
    int size = 0;
	vector<pair<int, int> > cheese;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	while (true) {
		DFS(make_pair(0, 0));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					int cnt = 0;
					for (int m = 0; m < 4; m++) {
						int nx = i + dx[m];
						int ny = j + dy[m];

						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

						if (map[nx][ny] == 0 && visited[nx][ny] == true)
							cnt++;
					}
					if (cnt >= 1)
						cheese.push_back(make_pair(i, j));
				}
			}
		}

		if (cheese.size() == 0) break;

		for (int i = 0; i < cheese.size(); i++) {
			int x = cheese[i].first;
			int y = cheese[i].second;

			map[x][y] = 0;
		}
		result++;

		memset(visited, false, sizeof(visited));
        size = cheese.size();
		cheese.clear();
	}

	cout << result << '\n';
	cout << size << '\n';

	return 0;
}