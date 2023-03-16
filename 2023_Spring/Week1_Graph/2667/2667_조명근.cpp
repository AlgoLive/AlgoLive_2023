#include <iostream>
#include <vector>
#include <algorithm>
const int MAX = 26;
using namespace std;
int map[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dcount;
int cnt;
vector<int> ans;
int n;

void dfs(pair<int, int> start)
{
    int x = start.first;
    int y = start.second;
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;
        if (map[nx][ny] == 0)
            continue;
        pair<int, int> tmp = make_pair(nx, ny);
        if (!visited[nx][ny])
        {
            dfs(tmp);
            dcount++;
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = a[j] - '0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((map[i][j] == 1) && (!visited[i][j]))
            {
                visited[i][j] = true;
                pair<int, int> tmp = make_pair(i, j);
                dcount = 1;
                dfs(tmp);
                ans.push_back(dcount);
                dcount = 1;
            }
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }
}

// 전역변수는 0으로 초기화해줌.
// 벡터 출력
// Sort하려면 역시 algorithm헤더 해줘야됨
// 좌표 -> pair , + 알아야할거는 이제 그 좌표 벗어나는 조건을 외우자!