#include <iostream>
#include <algorithm>

using namespace std;
pair<int, int> line[101];
int dp[101] = { 0, };

/** 전깃줄이 꼬이다?
 * 출발점(인덱스)가 더 아래인 상태에서 그 인덱스의 도착점보다 위를 가리킬 때
 *  그럼 안 꼬이려면?
 * 항상 이전 인덱스의 도착점보다 더 아래를 가리키면 된다.
 * -> LIS
 */

int main(){
    int n;
    int lis = 0; // lis의 길이

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> line[i].first >> line[i].second;
    }

    sort(line, line + n + 1); // 인덱스 오름차순 정렬

    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = 1; // 보편적인 LIS와 구도 동일
        for(int j=1; j<i; j++){
            if(line[i].second > line[j].second){ // 길이 확장 시도
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        lis = max(lis, dp[i]); // 매 반복문마다 lis의 길이 갱신
    }

    cout << n-lis << '\n'; // 정답은 빼기
    return 0;
}