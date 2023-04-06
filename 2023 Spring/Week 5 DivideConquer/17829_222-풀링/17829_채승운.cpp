#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int map[1024][1024];
int n;

int secondcheck(int a, int b){
    vector<int> v;
    for(int i=a; i<a+2; i++){ // 2*2 행렬 탐색
        for(int j=b; j<b+2; j++){
            v.push_back(map[i][j]);
        }
    }
    sort(v.begin(), v.end());
    return v[2]; // 오름차순 3번째 = 2번째로 큰 수
}

void pulling(int n){
    if(n == 1){ // n == 1이면 마지막으로 살아남는 숫자를 출력한다.
        cout << map[0][0] << '\n';
        return;
    } else {
        for(int i=0; i<n; i+=2){ // n * n 행렬을 순회하면서 두번째로 큰 수들을 n/2 * n/2 행렬에 몰아넣는다.
            for(int j=0; j<n; j+=2){
                map[i/2][j/2] = secondcheck(i, j);
            }
        }
        pulling(n/2); // 이후 n/2 행렬로 같은 작업을 반복한다.
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    pulling(n);
    return 0;
}