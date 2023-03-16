#include <iostream>
#include <cstring>

using namespace std;
int map[101][101];
int n;
int sum = 0;

int main(){
    
    memset(map, 0, sizeof(map));
    cin >> n;
    for(int i=0; i<n; i++){ // 예시 좌표를 상하반전시켜도 결과는 같다.
        int a, b;
        cin >> a >> b;
        for(int j=a; j<a+10; j++){
            for(int k=b; k<b+10; k++){
                if(!map[j][k]) map[j][k] = 1;
            }
        }
    }

    for(int i=0; i<100; i++){ // 1인 경우를 다 더해주면 된다.
        for(int j=0; j<100; j++){
            if(map[i][j] == 1) sum++;
        }
    }

    cout << sum;
    return 0;
}