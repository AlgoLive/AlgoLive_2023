#include <iostream>
#include <cstring>

using namespace std;

int R, C, T;
int map[50][50];
int temp[50][50];
int purifier_x[2];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void my_copy(int num)
{
    if (num == 1)
    {

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                temp[i][j] = map[i][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                map[i][j] = temp[i][j];
            }
        }
    }
}

int sum()
{
    int result = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            result += map[i][j];
        }
    }
    return result;
}

int main()
{
    cin >> R >> C >> T;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == -1)
                purifier_x[purifier_x[0] == 0 ? 0 : 1] = i;
        }
    }

    for (int m = 0; m < T; m++)
    {
        my_copy(1);

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (map[i][j] != 0 && map[i][j] != -1)
                {
                    int ndust = map[i][j] / 5;
                    int dir_cnt = 0;

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = dx[k] + i;
                        int ny = dy[k] + j;

                        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                            continue;
                        if (map[nx][ny] == -1)
                            continue;

                        temp[nx][ny] += ndust;
                        dir_cnt++;
                    }
                    temp[i][j] -= ndust * dir_cnt;
                }
            }
        }

        for (int i = purifier_x[0]; i > 0; i--)
            temp[i][0] = temp[i - 1][0];
        for (int j = 0; j < C - 1; j++)
            temp[0][j] = temp[0][j + 1];
        for (int i = 0; i < purifier_x[0]; i++)
            temp[i][C - 1] = temp[i + 1][C - 1];
        for (int j = C - 1; j >= 2; j--)
            temp[purifier_x[0]][j] = temp[purifier_x[0]][j - 1];
        temp[purifier_x[0]][1] = 0;
        temp[purifier_x[0]][0] = -1;

        for (int i = purifier_x[1]; i < R - 1; i++)
            temp[i][0] = temp[i + 1][0];
        for (int j = 0; j < C - 1; j++)
            temp[R - 1][j] = temp[R - 1][j + 1];
        for (int i = R - 1; i > purifier_x[0]; i--)
            temp[i][C - 1] = temp[i - 1][C - 1];
        for (int j = C - 1; j >= 2; j--)
            temp[purifier_x[1]][j] = temp[purifier_x[1]][j - 1];
        temp[purifier_x[1]][1] = 0;
        temp[purifier_x[1]][0] = -1;

        // for (int i = 0; i < R; i++)
        // {
        //     for (int j = 0; j < C; j++)
        //     {
        //         cout << temp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        my_copy(2);
    }

    cout << sum() + 2;
    return 0;
}