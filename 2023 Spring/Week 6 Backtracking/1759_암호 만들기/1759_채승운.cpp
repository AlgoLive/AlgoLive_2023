#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int l, c;
vector<char> v;
vector<char> input;

bool validcheck(){ // 최소 1개의 모음, 2개의 자음을 포함하는지 검사
    int mo = 0;
    int ja = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i] == 'a' || v[i] == 'i' || v[i] == 'e' || v[i] == 'o' || v[i] == 'u'){
            mo++;
        } else {
            ja++;
        }
    }
    return (mo >= 1 && ja >= 2);
}

void backtrack(int idx){
    if(v.size() == l){ // 사이즈가 다 찼을 떄
        if(validcheck()){ // 유효성 검사 후 출력
            for(int i=0; i<v.size(); i++){
                cout << v[i];
            }
            cout << '\n';
            return;
        }
    }

    for(int i=idx; i<c; i++){ // 백트래킹으로 순회
        v.push_back(input[i]);
        backtrack(i + 1);
        v.pop_back();
    }
}

int main(){
    cin >> l >> c;
    for(int i=0; i<c; i++){
        char a;
        cin >> a;
        input.push_back(a);
    }
    sort(input.begin(), input.end());
    backtrack(0);
    return 0;
}