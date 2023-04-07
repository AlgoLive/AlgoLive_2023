#include <iostream>

using namespace std;

int N;
long long X;
long long length[51];
long long dp[51];

long long patty(int n, long long x){
    // cout << "patty : " << n << ", " << x << " length[n] : " << length[n] <<'\n';

    if(n == 1 && x == 1) return 0;
    if(n == 1 && x == 2) return 1;
    if(n == 1 && x == 3) return 2;
    if(n == 1 && x == 4) return 3;
    if(n == 1 && x == 5) return 3;

    if(x == length[n]) {
        dp[n - 1] = dp[n - 1] == 0 ? patty(n - 1, length[n - 1]) : dp[n - 1];
        
        return 2 * dp[n - 1] + 1;
    }
    else if(length[n] / 2 + 1 < x && x < length[n]) {
        dp[n - 1] = dp[n - 1] == 0 ? patty(n - 1, length[n - 1]) : dp[n - 1];
        long long part = patty(n - 1, x - length[n - 1] - 2);
        return dp[n - 1] + part + 1;
    }
    else if(length[n] / 2 + 1 == x) {
        dp[n - 1] = dp[n - 1] == 0 ? patty(n - 1, length[n - 1]) : dp[n - 1];
        return dp[n - 1] + 1;
    }
    else if(1 < x && x < length[n] / 2 + 1) {
        return patty(n - 1, x - 1);
    }
    else if(x == 1) {
        return 0;
    }

    return 0;
}

int main() {
    cin >> N >> X;

    length[0] = 1;
    for(int i = 1; i <= N; i++)
        length[i] = 2 * length[i - 1] + 3;
    
    // cout << length[50];
    // for(int i = 1; i <= length[N]; i++)
        // cout << patty(N, i) << '\n';
    cout << patty(N, X);
    return 0;
}

/**
 * 레벨-0 버거는 패티만으로 이루어져 있다.
 * 레벨-L 버거는 햄버거번, 레벨-(L-1) 버거, 패티, 레벨-(L-1)버거, 햄버거번으로 이루어져 있다. (L ≥ 1)
 * 
 * 1
 * P
 * 
 * 5
 * B P P P B
 * 
 * 13
 * 1  2 3 4 5 6  7
 * B  B P P P B  P  B P P P B  B 
 * 
 * 29
 * 1  2  3 4 5 6 7  8  9 10111213 14  15 16 1718192021 22 2324252627 28  29
 * B  B  B P P P B  P  B P P P B  B   P  B  B P P P B  P  B P P P B  B   B 
 * 
 * N(2, 7)
 * 
 * 
 */

    // if(n == 1 && x == 1) return 0;
    // if(n == 1 && x == 2) return 1;
    // if(n == 1 && x == 3) return 2;
    // if(n == 1 && x == 4) return 3;
    // if(n == 1 && x == 5) return 3;

    // if(x == 2 * length[n - 1] + 3) {
    //     return 2 * patty(n - 1, (x - 3) / 2) + 1;
    // }
    // else if(length[n - 1] + 2 < x && x < 2 * length[n - 1] + 3) {
    //     long long before = patty(n - 1, (x - 3) / 2);
    //     long long part = patty(n - 1, x - (length[n] / 2 + 1));
    //     return before + 1 + part;
    // }
    // else if(length[n - 1] + 2 == x) {
    //     return patty(n - 1, x - 2) + 1;
    // }
    // else if(1 < x && x < length[n - 1] + 2) {
    //     return patty(n - 1, x - 1);
    // }
    // else if(x == 1) {
    //     return 0;
    // }

    // return 0;