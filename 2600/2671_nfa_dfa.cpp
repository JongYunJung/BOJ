// BOJ 2671 - 잠수함 식별 (1013 Contact 문제와 동일)
// 정규화 문제
#include <iostream>
#include <string>
using namespace std;

const int E = 9;
const int tr[10][2] = {
    // 0, 1
    {5, 1}, // 0
    {2, E}, // 1
    {3, E}, // 2
    {3, 4}, // 3
    {5, 7}, // 4
    {E, 6}, // 5
    {5, 1}, // 6
    {8, 7}, // 7
    {3, 6}, // 8
    {E, E}  // 9
};

bool regex_match_hsjang(string& str) {
    int state = 0;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i] - '0';
        state = tr[state][ch];
    }
    return state == 4 || state == 6 || state == 7;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    cin >> str;
    cout << (regex_match_hsjang(str) ? "SUBMARINE" : "NOISE") << '\n';
    
    return 0;
}
