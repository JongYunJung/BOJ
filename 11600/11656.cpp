// BOJ 11656 - 접미사 배열
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    cin >> str;
    
    vector<string> answers;
    answers.push_back(str);
    while (str.length() > 1) {
        str = str.substr(1, str.length() - 1);
        answers.push_back(str);
    }
    
    sort(answers.begin(), answers.end());
    
    for (string str : answers) {
        cout << str << '\n';
    }
    
    return 0;
}
