#include <iostream>
#include <string>

const int MAX = 201;
char map[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int R, C, N;
using namespace std;

void instbomb()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == 'O')
            {
                map[i][j] = '1';
            }
            if (map[i][j] == '.')
            {
                map[i][j] = 'O';
            }
        }
    }
}
void boom()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == '1')
            {
                map[i][j] = '.';
                int nx, ny;
                for (int k = 0; k < 4; k++)
                {
                    nx = i + dx[k];
                    ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                    {
                        continue;
                    }
                    if (map[nx][ny] == '1')
                        continue;
                    map[nx][ny] = '.';
                }
            }
        }
    }
}

void printsit()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == '1')
            {
                cout << 'O';
            }
            else
            {
                cout << map[i][j];
            }
        }
        cout << endl;
    }
}

int main()
{
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < C; j++)
        {
            map[i][j] = tmp[j];
        }
    }
    if (N == 1)
    {
        printsit();
    }
    else
    {
        for (int i = 2; i <= N; i++)
        {
            if (i % 2 == 0)
            {
                instbomb();
            }
            else
            {
                boom();
            }
        }
        printsit();
    }
}