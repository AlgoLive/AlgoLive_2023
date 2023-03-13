#include <iostream>
#include <vector>

using namespace std;

int main() {
    int K;
    int result = 0;
    vector<int> stack;

    cin >> K;
    for(int i = 0; i < K; i++) {
        int num;
        cin >> num;
        if(num == 0)
            stack.pop_back();
        else
            stack.push_back(num);
    }

    for(int i = 0; i < stack.size(); i++){
        result += stack[i];
    }

    cout << result;

    return 0;
}