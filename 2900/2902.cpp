// BOJ 2902 - KMP는 왜 KMP일까?
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    cin >> str;
    
    string answer = "";
    int i = 0;
    while (i < str.length()) {
        if (i == 0) {
            answer += str[i];
        } else if (str[i] == '-') {
            answer += str[i + 1];
            i++;
        }
        i++;
    }
    
    cout << answer << '\n';
    return 0;
}
