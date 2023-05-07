#include <iostream>
using namespace std;

int n;
int prime[5] = {2, 3, 5, 7};
// 소수: 2, 3, 5, 7

bool isPrime(int num){
    for(int i=2; i*i<=num; i++){
        if(num%i == 0) return false;
    }
    return true;
}
void backT(int num, int len){
    if(len == n){
        cout << num << "\n";
        return;
    }
    for(int i=1; i<=9; i++){
        int tmp = num*10 + i;
        if(isPrime(tmp)){
            backT(tmp, len+1);
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<4; i++){
        backT(prime[i], 1);
    }

    return 0;
}
