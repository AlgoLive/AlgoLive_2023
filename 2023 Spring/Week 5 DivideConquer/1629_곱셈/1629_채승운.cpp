#include <iostream>

using namespace std;
long long a, b, c;

long long func(long long a, long long b, long long c){   
    if(b == 0) return 1;
    if(b == 1) return a % c;

    long long num = func(a, b/2, c); // 분할정복으로 절반의 상황을 구해온다.
    if(b % 2 == 0){ // 곱셈 결과를 c로 나눈 나머지를 구한다.
        return (num * num % c); 
    } else { // 홀수면 a 한번 더 곱해주어야 한다.
        return (num * num % c) * (a % c) % c; // 모듈러 원리 적용
    }
}

int main(){
    cin >> a >> b >> c;
    cout << func(a, b, c);
    return 0;
}