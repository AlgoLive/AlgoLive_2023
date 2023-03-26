#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

int N, M;
char map[10][10];
bool visited[10][10][10][10];

pair<int, int> hole;
pair<int, int> red;
pair<int, int> blue;

bool isPossibleWay(int x, int y)
{
    return map[x][y] == '.' || map[x][y] == 'O';
}

bool hasSharpX(int from, int to, int y)
{
    for (int i = from + 1; i < to; i++)
    {
        if (map[i][y] == '#')
            return true;
    }

    return false;
}

bool hasSharpY(int from, int to, int x)
{
    for (int i = from + 1; i < to; i++)
    {
        if (map[x][i] == '#')
            return true;
    }

    return false;
}

bool hasHoleX(int from, int to, int y)
{
    for (int i = from + 1; i < to; i++)
    {
        if (map[i][y] == 'O')
            return true;
    }

    return false;
}

bool hasHoleY(int from, int to, int x)
{
    for (int i = from + 1; i < to; i++)
    {
        if (map[x][i] == 'O')
            return true;
    }

    return false;
}

tuple<int, int, int, int, int> BFS(tuple<int, int, int, int, int> start)
{
    // (red_xy, blue_xy, depth)
    int i, j, m, n;
    queue<tuple<int, int, int, int, int>> q;

    q.push(start);

    while (!q.empty())
    {
        tuple<int, int, int, int, int> cur = q.front();
        q.pop();

        int r_x = get<0>(cur);
        int r_y = get<1>(cur);
        int b_x = get<2>(cur);
        int b_y = get<3>(cur);

        visited[r_x][r_y][b_x][b_y] = true;
        
        // cout << r_x << r_y << b_x << b_y << get<4>(cur) << ' ';
        // if(r_y == b_y)
        //     cout << "hasSharpX : " << hasSharpX(r_x, b_x, r_y) << " hasHoleX : " << hasSharpX(r_x, b_x, r_y);
        // else if (r_x == b_x)
        //     cout << "hasSharpY : " << hasSharpY(r_y, b_y, r_x) << " hasHoleY : " << hasSharpY(r_y, b_y, r_x);
        // cout << '\n';

        if (get<4>(cur) > 10)
            continue;
        if (map[b_x][b_y] == 'O')
            continue;
        if (map[r_x][r_y] == 'O')
            return cur;

        // 1. 아래로
        if (r_y == b_y 
            && !hasSharpX(r_x, b_x, r_y) && !hasSharpX(b_x, r_x, r_y)
            && !hasHoleX(r_x, b_x, r_y) && !hasHoleX(b_x, r_x, r_y))
        {
            // 사이에는 #, O 모두 없어야함.
            if (r_x > b_x) // R먼저 이동
            {
                for (i = r_x + 1; map[i][r_y] != '#'; i++)
                {
                    if (map[i - 1][r_y] == 'O')
                        break;
                }
                i--;
                // R이 구멍에 빠지면 B도 구멍에 위치
                // R이 구멍에 안 빠지면, B는 R보다 한 칸 위에 위치 (#이 사이에 없기 때문)
                map[i][r_y] == 'O' ? m = i : m = i - 1;
            }
            else if (r_x < b_x) // B먼저 이동
            {
                for (m = b_x + 1; map[m][b_y] != '#'; m++)
                {
                    if (map[m - 1][b_y] == 'O')
                        break;
                }
                m--;
                // B이 구멍에 빠지면 R도 구멍에 위치
                // B이 구멍에 안 빠지면, R는 B보다 한 칸 위에 위치 (#이 사이에 없기 때문)
                map[m][b_y] == 'O' ? i = m : i = m - 1;
            }
        }
        else
        {
            for (i = r_x + 1; map[i][r_y] != '#'; i++)
            {
                if (map[i - 1][r_y] == 'O')
                    break;
            }
            i--;
            for (m = b_x + 1; map[m][b_y] != '#'; m++)
            {
                if (map[m - 1][b_y] == 'O')
                    break;
            }
            m--;
        }
        if (visited[i][r_y][m][b_y] == false)
        {
            q.push(make_tuple(i, r_y, m, b_y, get<4>(cur) + 1));
            visited[i][r_y][m][b_y] = true;
        }

        // 2. 우측으로
        if (r_x == b_x 
            && !hasSharpY(r_y, b_y, r_x) && !hasSharpY(b_y, r_y, r_x)
            && !hasHoleY(r_y, b_y, r_x) && !hasHoleY(b_y, r_y, r_x))
        {
            if (r_y > b_y) // R먼저 이동
            {
                for (j = r_y + 1; map[r_x][j] != '#'; j++)
                {
                    if (map[r_x][j - 1] == 'O')
                        break;
                }
                j--;
                // R이 구멍에 빠지면 B도 구멍에 위치
                // R이 구멍에 안 빠지면, B는 R보다 한 칸 왼쪽에 위치 (#이 사이에 없기 때문)
                map[r_x][j] == 'O' ? n = j : n = j - 1;
            }
            else if (r_y < b_y) // B먼저 이동
            {
                for (n = b_y + 1; map[b_x][n] != '#'; n++)
                {
                    if (map[b_x][n - 1] == 'O')
                        break;
                }
                n--;
                // B이 구멍에 빠지면 R도 구멍에 위치
                // B이 구멍에 안 빠지면, R는 B보다 한 칸 왼쪽에 위치 (#이 사이에 없기 때문)
                map[b_x][n] == 'O' ? j = n : j = n - 1;
            }
        }
        else // 중간에 #이 있는 경우 어떻게 이동하든 상관 없음
        {
            for (j = r_y + 1; map[r_x][j] != '#'; j++)
            {
                if (map[r_x][j - 1] == 'O')
                    break;
            }
            j--;
            for (n = b_y + 1; map[b_x][n] != '#'; n++)
            {
                if (map[b_x][n - 1] == 'O')
                    break;
            }
            n--;
        }
        if (visited[r_x][j][b_x][n] == false)
        {
            q.push(make_tuple(r_x, j, b_x, n, get<4>(cur) + 1));
            visited[r_x][j][b_x][n] = true;
        }

        // 3. 위측으로
        if (r_y == b_y 
            && !hasSharpX(r_x, b_x, r_y) && !hasSharpX(b_x, r_x, r_y)
            && !hasHoleX(r_x, b_x, r_y) && !hasHoleX(b_x, r_x, r_y))
        {
            if(r_x < b_x) { // R먼저 이동 (작은거 먼저)
                for (i = r_x - 1; map[i][r_y] != '#'; i--)
                {
                    if (map[i + 1][r_y] == 'O')
                        break;
                }
                i++;
                // R이 구멍에 빠지면 B도 구멍에 위치
                // R이 구멍에 안 빠지면, B는 R보다 한 칸 아래에 위치 (#이 사이에 없기 때문)
                map[i][r_y] == 'O' ? m = i : m = i + 1;
            }
            else if(r_x > b_x) { // B먼저 이동 (작은거 먼저)
                for (m = b_x - 1; map[m][b_y] != '#'; m--)
                {
                    if (map[m + 1][b_y] == 'O')
                        break;
                }
                m++;
                // B이 구멍에 빠지면 R도 구멍에 위치
                // B이 구멍에 안 빠지면, R는 B보다 한 칸 아래에 위치 (#이 사이에 없기 때문)
                map[m][b_y] == 'O' ? i = m : i = m + 1;
            }
        }
        else {
            for (i = r_x - 1; map[i][r_y] != '#'; i--)
            {
                if (map[i + 1][r_y] == 'O')
                    break;
            }
            i++;
            for (m = b_x - 1; map[m][b_y] != '#'; m--)
            {
                if (map[m + 1][b_y] == 'O')
                    break;
            }
            m++;
        }
        if (visited[i][r_y][m][b_y] == false)
        {
            q.push(make_tuple(i, r_y, m, b_y, get<4>(cur) + 1));
            visited[i][r_y][m][b_y] = true;
        }
        
        // 4. 왼쪽으로
        if (r_x == b_x 
            && !hasSharpY(r_y, b_y, r_x) && !hasSharpY(b_y, r_y, r_x)
            && !hasHoleY(r_y, b_y, r_x) && !hasHoleY(b_y, r_y, r_x))
        {
            if(r_y < b_y) { // R먼저 이동 (작은거 먼저)
                for (j = r_y - 1; map[r_x][j] != '#'; j--)
                {
                    if (map[r_x][j + 1] == 'O')
                        break;
                }
                j++;
                // R이 구멍에 빠지면 B도 구멍에 위치
                // R이 구멍에 안 빠지면, B는 R보다 한 칸 오른쪽에 위치 (#이 사이에 없기 때문)
                map[r_x][j] == 'O' ? n = j : n = j + 1;
            }
            else if(r_y > b_y) {
                for (n = b_y - 1; map[b_x][n] != '#'; n--)
                {
                    if (map[b_x][n + 1] == 'O')
                        break;
                }
                n++;
                // B이 구멍에 빠지면 R도 구멍에 위치
                // B이 구멍에 안 빠지면, R는 B보다 한 칸 오른쪽쪽에 위치 (#이 사이에 없기 때문)
                map[b_x][n] == 'O' ? j = n : j = n + 1;
            }
        }
        else {
            for (j = r_y - 1; map[r_x][j] != '#'; j--)
            {
                if (map[r_x][j + 1] == 'O')
                    break;
            }
            j++;
            for (n = b_y - 1; map[b_x][n] != '#'; n--)
            {
                if (map[b_x][n + 1] == 'O')
                    break;
            }
            n++;
        }
        if (visited[r_x][j][b_x][n] == false)
        {
            q.push(make_tuple(r_x, j, b_x, n, get<4>(cur) + 1));
            visited[r_x][j][b_x][n] = true;
        }
    }

    return make_tuple(0, 0, 0, 0, -1);
}

int main()
{
    int result = 0;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string line;

        cin >> line;
        for (int j = 0; j < M; j++)
        {
            map[i][j] = line[j];
            if (map[i][j] == 'O')
                hole = make_pair(i, j);
            else if (map[i][j] == 'R')
            {
                red = make_pair(i, j);
                map[i][j] = '.';
            }
            else if (map[i][j] == 'B')
            {
                blue = make_pair(i, j);
                map[i][j] = '.';
            }
        }
    }
    memset(visited, false, sizeof(visited));

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    tuple<int, int, int, int, int> temp = BFS(make_tuple(red.first, red.second, blue.first, blue.second, 0));
    // cout << "result" << '\n';
    // cout << get<0>(temp) << get<1>(temp) << get<2>(temp) << get<3>(temp) << get<4>(temp) << '\n';
    if(get<0>(temp) == get<2>(temp) && get<1>(temp) == get<3>(temp))
        result = -1;
    else if(hole.first == get<2>(temp) && hole.second == get<3>(temp))
        result = -1;
    else if(get<4>(temp) > 10)
        result = -1;
    else result = get<4>(temp);

    cout << result;
    return 0;
}