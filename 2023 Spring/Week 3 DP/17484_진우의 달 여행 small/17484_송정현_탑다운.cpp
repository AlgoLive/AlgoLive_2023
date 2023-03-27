#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int n, m, res=INF;
int map[1001][1001], dp[1001][1001][4];
//0=왼, 1=가운데, 2=오
//topdown
int DP(int x, int y, int dir){
    if(x == n)  return 0;
    if(dp[x][y][dir] != INF)    return dp[x][y][dir];
    if(dir != 0 && y-1 >= 0){   //왼
        dp[x][y][dir] = DP(x+1, y-1, 0) + map[x][y];
    }
    if(dir != 1){   //가운데
        dp[x][y][dir] = min(dp[x][y][dir], DP(x+1, y, 1) + map[x][y]);
    }
    if(dir != 2 && y+1 < m){    //오
        dp[x][y][dir] = min(dp[x][y][dir], DP(x+1, y+1, 2) + map[x][y]);
    }
    return dp[x][y][dir];
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    memset(dp, INF, sizeof(dp));
    for(int i=0; i<m; i++){
        res = min(res, DP(0, i, 3));
    }
    cout << res;

    return 0;
}