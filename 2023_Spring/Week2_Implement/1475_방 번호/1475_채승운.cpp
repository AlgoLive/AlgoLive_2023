#include <iostream>
#include <cstring>

using namespace std;
int num[10];

int main(){
    int cnt = 0;
    string str;

    cin >> str;
    for(int j=0; j<str.length(); j++){
        int a = str[j] - '0';
        num[a]++;
    }

    int sixnine = num[6] + num[9];
    if(sixnine % 2 == 0){
        num[6] = sixnine / 2;
        num[9] = sixnine / 2;
    } else {
        num[6] = sixnine / 2 + 1;
        num[9] = sixnine / 2 + 1;
    }

    for(int i=0; i<10; i++){
        cnt = max(cnt, num[i]);
    }
    cout << cnt;
    return 0;
}
