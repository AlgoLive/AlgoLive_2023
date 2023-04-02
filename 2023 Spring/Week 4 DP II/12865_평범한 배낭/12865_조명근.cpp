#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 101;
const int MAXK = 100001;
int jw[MAXN][2];
int dp[MAXN][MAXK];
int N, K;

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> jw[i][0] >> jw[i][1];
    }
    int res = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            // 비교하다가 더 작은 중량인데 담은 케이스를 가져오기 위한 코드
            if (j < jw[i][0])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else if (j >= jw[i][0])
            {
                dp[i][j] = max(jw[i][1] + dp[i - 1][j - jw[i][0]], dp[i - 1][j]);
                res = max(res, dp[i][j]);
            }
        }
    }
    cout << res;
}
/*저 if문 하나 조건 따지는게 중요했음. 그릴떄 더 자세한 상황 생각 안해서 아쉽*/