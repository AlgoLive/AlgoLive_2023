#include <iostream>
#include <string>

using namespace std;

string arr1;
string arr2;

int dp[1001][1001];

int i, j;

int N, M;

int main() {
    cin >> arr1;
    cin >> arr2;
    N = arr1.length();
    M = arr2.length();
    
    // cout << M << '\n';

    // for(i = 0; i < M; i++){
    //     for(j = 0; j < N; j++){
    //         if(arr2[i] == arr1[j]){
    //             dp[i] = make_pair(1, j);
    //             for(int k = i; k >= 0; k--){
    //                 if(dp[k].second < j)
    //                     dp[i].first = max(dp[k].first + 1, dp[i].first);
    //             }
    //         }
    //     }
    // }
    /*
        결국 2차원으로 확장해야한다!
    */

    for(i = 1; i <= N; i++){
        for(j = 1; j <= M; j++){
            if(arr1[i - 1] == arr2[j - 1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // for(int i = 0; i <= N; i++){
    //     for(int j = 0; j <= M; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[N][M];

    return 0;
}
// ACAK
// 
//   C A P C A K
// A 0 1 1 1 1 1
// C 1 1 1 2 2 2
// A 1 2 2 2 3 3
// Y 1 2 2 2 3 3
// K 1 2 2 2 3 4
// P 1 2 2 2 3 4 
