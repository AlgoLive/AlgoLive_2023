#include <iostream>
#include <limits.h>

using namespace std;

int N;
int number[11];
int oper[4];
int ans_max = INT_MIN;
int ans_min = INT_MAX;

int stack[11];
int stack2[11];
int top = -1;
int top2 = -1;
char ops[4] = {'+', '-', '*', '/'};

void DFS(int result, int num_idx) {
    // cout << result << ", " << num_idx << '\n';

    if(num_idx + 1 >= N){
        ans_max = max(ans_max, result);
        ans_min = min(ans_min, result);
        
        // for(int j = 0; j <= top; j++)
        //     cout << ops[stack[j]] << " ";
        // for(int j = 0; j <= top2; j++)
        //     cout << stack2[j] << " ";

        // cout << "max, min : " << ans_max << ", " << ans_min << '\n';

        return;
    }

    for(int i = 0; i < 4; i++){
        if(oper[i] != 0){
            oper[i]--;
            stack[++top] = i;

            if(i == 0){
                stack2[++top2] = result + number[num_idx + 1];
                DFS(result + number[num_idx + 1], num_idx + 1);
            }
            else if(i == 1){
                stack2[++top2] = result - number[num_idx + 1];   
                DFS(result - number[num_idx + 1], num_idx + 1);
            }
            else if(i == 2){
                stack2[++top2] = result * number[num_idx + 1];
                DFS(result * number[num_idx + 1], num_idx + 1);
            }
            else if(i == 3){
                stack2[++top2] = result / number[num_idx + 1];
                DFS(result / number[num_idx + 1], num_idx + 1);
            }

            top--;
            top2--;
            oper[i]++;
        }
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> number[i];
    for(int i = 0; i < 4; i++)
        cin >> oper[i];

    stack2[++top2] = number[0];

    DFS(number[0], 0);

    cout << ans_max << '\n' << ans_min;

    return 0;
}
