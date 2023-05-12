#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
char password[15];
bool visited[15];

char stack[15];
int top = -1;

vector<string> result;

bool isAble(){
    int consonant = 0;
    int vowel = 0;
    for(int i = 0; i < top; i++){
        if(stack[i] == 'a' || stack[i] == 'e' || stack[i] == 'i' || stack[i] == 'o' || stack[i] == 'u')
            vowel++;
        else
            consonant++;
    }

    return consonant >= 2 && vowel >= 1;
}

void backtracking(int index, int depth){
    // cout << password[index] << ", " << depth << '\n';

    if(depth >= L - 1) {
        // cout << "return : ";
        stack[++top] = password[index];

        if(isAble()){
            string temp;
            for(int i = 0; i < top; i++){
                temp += stack[i];
            }
            // cout << temp << '\n';
            result.push_back(temp);
        }

        top--;

        return;
    }

    for(int i = 0; i < C; i++){
        if(visited[i] == false && password[index] < password[i]) {
            visited[i] = true;
            stack[++top] = password[i];
            
            backtracking(i, depth + 1);

            visited[i] = false;
            top--;
            // for(int j = 0; j < top; j++){
            //     cout << stack[j] << " ";    
            // }
            // cout << '\n';
        }
    }
}

int main(){
    cin >> L >> C;
    for(int i = 0; i < C; i++){
        cin >> password[i];
    }

    memset(visited, false, sizeof(visited));

    for(int i = 0; i < C; i++){
        stack[++top] = password[i];
        visited[i] = true;
        backtracking(i, 0);
        top--;
        visited[i] = false;
    }

    sort(result.begin(), result.end());

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < L; j++){
            cout << result[i][j];
        }
        cout << '\n';
    }

    return 0;
}