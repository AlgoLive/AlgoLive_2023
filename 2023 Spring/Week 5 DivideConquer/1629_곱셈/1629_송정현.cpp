#include <iostream>
using namespace std;

long long a, b, c;

long long power(long long a, long long b, long long c){
    if(b == 0) return 1;    // 모든 수의 0제곱은 1
    if(b == 1) return a%c;  // 모든 수의 1제곱은 자기 자신

    long long k = power(a, b/2, c);

    if(b % 2 == 0){   // b가 짝수일 때
        return (k * k) % c;
    }
    else{   // b가 홀수일 때
        return ((k * k) % c) * a % c;
    }
}
int main(){
    cin >> a >> b >> c;
    cout << power(a, b, c);

    return 0;
}
/**
 * 2^10 = 2^5 * 2^5     // b가 짝수
 * 2^5 = 2^2 * 2^2 * 2  // b가 홀수
*/