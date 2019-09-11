// BOJ 10798 - 세로 읽기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int maxLength = 0;
    string str[5];
    
    for (int i = 0; i < 5; i++) {
        cin >> str[i];
        maxLength = max(maxLength, (int)str[i].length());
    }
    
    string answer = "";
    for (int i = 0; i < maxLength; i++) {
        for (int j = 0; j < 5; j++) {
            if (i >= str[j].length()) continue;
            answer += str[j][i];
        }
    }
    
    cout << answer << '\n';
    return 0;
}
