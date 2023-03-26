#include <iostream>

using namespace std;

int n, a, b, cnt;
int arr[100][100];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        for(int j=a; j<a+10; j++){
            for(int k=b; k<b+10; k++){
                arr[k][j] = 1;
            }
        }
    }
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(arr[i][j]==1){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}