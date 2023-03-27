#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 1=0
 * 2-1=1
 * 3-1=1
 * 4-2-1=2
 * 5-4-2-1=3
 * 6-3-1=2 / 6-2-1=2
 * 7-6-3-1=3
 * 8-4-2-1=3
 * 9-3-1=2
 * 10-9-3-1=3
 */

int k;
int dp[1000001]={0};

int main(){
    cin >> k;
    // 바텀업
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int i=4; i<k+1; i++){
        if(i%6 == 0){
            dp[i]=min(min(dp[i/3], dp[i/2]), dp[i-1])+1;
        }
        else if(i%3 == 0){
            dp[i]=min(dp[i/3], dp[i-1])+1;
        }
        else if(i%2 == 0){
            dp[i]=min(dp[i/2], dp[i-1])+1;
        }
        else{
            dp[i]=dp[i-1]+1;
        }
    }

    cout << dp[k];
    return 0;
}