#include <iostream>
#include <stack>

using namespace std;

int k, n, sum=0;
stack<int> s;

int main(){
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> n;
        if(n == 0){
            s.pop();
        }
        else s.push(n);
    }
    int size = s.size();
    for(int i=0; i<size; i++){
        sum += s.top();
        s.pop();
    }
    cout << sum;

    return 0;
}