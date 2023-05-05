#include <iostream>
#include <cstring>

using namespace std;

int mem[11][11];
bool visited[11];
int answer, t;

void backtrack(int sum, int cnt){
    if(cnt == 11){ // 모든 선수가 배치되었다면 합 갱신
        answer = max(answer, sum);
        return;
    }

    for(int i=0; i<11; i++){
        if(mem[cnt][i] != 0 && !visited[i]){ // cnt번째 선수가 i번째 포지션으로 갈 수 있다면
            sum += mem[cnt][i];
            visited[i] = true;
            backtrack(sum, cnt + 1); // 백트래킹으로 순회
            sum -= mem[cnt][i];
            visited[i] = false;
        }
    }

}

int main(){
    cin >> t;
    for(int a=0; a<t; a++){
        answer = 0;
        memset(mem, 0, sizeof(mem));
        memset(visited, false, sizeof(visited)); // 테케마다 초기화

        for(int i=0; i<11; i++){
            for(int j=0; j<11; j++){
                cin >> mem[i][j];
            }
        }
        backtrack(0, 0);
        cout << answer << '\n';
    }
    return 0;  
}