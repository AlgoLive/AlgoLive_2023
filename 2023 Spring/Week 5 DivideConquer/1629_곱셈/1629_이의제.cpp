#include <iostream>

using namespace std;

long long A, B, C;

long long remainder(long long a, long long b, long long c){
    // cout << a << " " << b << " " << c << "\n";
    // if(b == 0) b는 자연수
    //     return 1;
    if(b == 1)
        return a % c;
    else {
        if(b % 2 == 0){
            long long temp = remainder(a, b / 2, c);
            return (temp * temp) % c;
        }
        else {
            long long temp = remainder(a, (b - 1) / 2, c);
            return ((temp * temp % c) * (a % c)) % c;
        }
    }
}

int main() {
    cin >> A >> B >> C;

    cout << remainder(A, B, C);
    return 0;
}