#include <iostream>
#include <cstring>

using namespace std;
int t;
int n;
int dp[3][100001]; // 스티커의 최댓값
int s[3][100001]; // 스티커 값

int main(){
    cin >> t;
    for(int a=0; a<t; a++){
        memset(dp, 0, sizeof(dp));
        memset(s, 0, sizeof(s));

        cin >> n;
        for(int i=1; i<=2; i++){
            for(int j=1; j<=n; j++){
                cin >> s[i][j];
            }
        } // 스티커 입력

        dp[1][1] = s[1][1];
        dp[2][1] = s[2][1];

        dp[1][2] = dp[2][1] + s[1][2];
        dp[2][2] = dp[1][1] + s[2][2]; // 점화식 초기값 설정

        for(int i=3; i<=n; i++){
            dp[1][i] = max(dp[2][i-1], dp[2][i-2]) + s[1][i];
            dp[2][i] = max(dp[1][i-1], dp[1][i-2]) + s[2][i];
        }

        cout << max(dp[1][n], dp[2][n]) << '\n';
    }
    return 0;
}
/**
 * 포도주 문제와 유사하다.
 * 스티커의 최댓값 형성 구도는 마지막줄 위칸 기준 다음과 같다.
 * VOV
 * OVO
 * 
 * OOV
 * VOO
 * 오직 둘 중 한 경우에서 최댓값이 결정된다.
 * 점화식: dp[1][i] = dp[2][i-1] vs dp[2][i-2] + s[1][i];
*/