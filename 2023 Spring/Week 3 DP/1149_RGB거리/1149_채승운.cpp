#include <iostream>

using namespace std;
int n;
int dp[1001][3]; // n개 집을 칠하는 비용의 최솟값
int map[1001][3]; // 각 집의 색깔별 비용
const int RED = 0;
const int GREEN = 1;
const int BLUE = 2;

int draw(int i, int color){ // Top-Down
    if(dp[i][color] == 0 && i > 1){ // 메모이제이션 여부 확인 + i가 1이면 0번째 집을 칠하는 이상현상 방지
        if(color == RED){
            dp[i][color] = min(draw(i-1, GREEN), draw(i-1, BLUE)) + map[i][color];
        } else if(color == GREEN){
            dp[i][color] = min(draw(i-1, RED), draw(i-1, BLUE)) + map[i][color];
        } else {
            dp[i][color] = min(draw(i-1, RED), draw(i-1, GREEN)) + map[i][color];
        }
    }
    return dp[i][color];
}

int main(){
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin >> map[i][j];
        }
    }

    dp[1][RED] = map[1][RED];
    dp[1][GREEN] = map[1][GREEN];
    dp[1][BLUE] = map[1][BLUE]; // 첫 집


    for(int i=2; i<=n; i++){ // Bottom-Up
        dp[i][RED] = map[i][RED] + min(dp[i-1][GREEN], dp[i-1][BLUE]);
        dp[i][BLUE] = map[i][BLUE] + min(dp[i-1][GREEN], dp[i-1][RED]);
        dp[i][GREEN] = map[i][GREEN] + min(dp[i-1][BLUE], dp[i-1][RED]);
    }

    // 마지막 집의 색깔에 따른 계산 결과 비교
    int resultBottomUp = min(dp[n][RED], min(dp[n][GREEN], dp[n][BLUE]));
    int resultTopDown = min(draw(n, RED), min(draw(n, GREEN), draw(n, BLUE)));
    cout << resultBottomUp;
    return 0;
}