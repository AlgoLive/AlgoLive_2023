#include <iostream>

using namespace std;
int n;
int answer = 0;
int arr[16];

bool validcheck(int cnt){
    for(int i=0; i<cnt; i++){ // 대각선 혹은 열이 같을 때
        if(arr[i] == arr[cnt] || abs(i - cnt) == abs(arr[i] - arr[cnt])){
            return false;
        }
    }
    return true;
}

void backtrack(int cnt){
    if(cnt == n){ // 성공했다면 케이스에 하나 추가
        answer++;
        return;
    }

    for(int i=0; i<n; i++){
        arr[cnt] = i; // cnt번째 행에 i번째 열에 퀸을 배치
        if(validcheck(cnt)){ // 이것이 가능하다면 다음으로
            backtrack(cnt + 1);
        }
    }
}

int main(){
    cin >> n;
    backtrack(0);
    cout << answer << '\n';
    return 0;
}