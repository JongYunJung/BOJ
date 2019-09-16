// BOJ 1159 - 농구 경기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> lastName(26);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        lastName[str[0] - 'a']++;
    }
    
    string answer = "";
    for (int i = 0; i < lastName.size(); i++) {
        if (lastName[i] >= 5) {
            answer += i + 'a';
        }
    }
    
    if (answer.empty()) {
        cout << "PREDAJA" << '\n';
    } else {
        cout << answer << '\n';
    }
    
    return 0;
}
