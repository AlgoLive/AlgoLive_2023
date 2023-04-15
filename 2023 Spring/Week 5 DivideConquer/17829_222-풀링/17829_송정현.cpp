#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[1025][1025];

int solve(int x, int y, int size){
    vector<int> v;
    if(size == 2){
        v.push_back(map[x][y]);
        v.push_back(map[x][y+1]);
        v.push_back(map[x+1][y]);
        v.push_back(map[x+1][y+1]);
        sort(v.begin(), v.end());
        return v[2];
    }
    else{
        v.push_back(solve(x, y, size/2));
        v.push_back(solve(x+size/2, y, size/2));
        v.push_back(solve(x, y+size/2, size/2));
        v.push_back(solve(x+size/2, y+size/2, size/2));
        sort(v.begin(), v.end());
        return v[2];
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    cout << solve(0, 0, n) << "\n";

    return 0;
}
