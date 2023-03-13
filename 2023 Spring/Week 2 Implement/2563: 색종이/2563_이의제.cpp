#include <iostream>

using namespace std;

int paper[101][101];

int main() {
    int num;
    int area = 0;

    cin >> num;
    for(int i = 0; i < num; i++){
        int x, y;
        cin >> x >> y;

        for(int m = x + 1; m <= x + 10; m++){
            for(int n = y + 1; n <= y + 10; n++){
                if(paper[m][n] == 0){
                    area++;
                    paper[m][n] = 1;
                }
            }
        }
    }
    cout << area;

    return 0;
}