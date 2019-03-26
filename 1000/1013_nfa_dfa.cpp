// BOJ 1013 - Contact
// 정규 표현식 관련된 문제
#include <iostream>
#include <string>
using namespace std;

// 정규표현식 형태이므로..
// DFA(Deterministic Finite Automata)를 그려서 O(N) 만에 문제를 해결할 수 있다.
// 주어진 패턴 (100+1+|01)+ 을 NFA(Non-deterministic Finite Automata) 으로 먼저 그리고 나서
// DFA 로 변환 한다.
// 자세한 부분들은 Automata 에 대해 공부해야할 것 같다..
const int FAIL = 9;
const int tr[10][2] = {
    //   0, 1
    {5, 1},         // 0
    {2, FAIL},      // 1
    {3, FAIL},      // 2
    {3, 4},         // 3
    {5, 7},         // 4
    {FAIL, 6},      // 5
    {5, 1},         // 6
    {8, 7},         // 7
    {3, 6},         // 8
    {FAIL, FAIL}    // 9
};

bool check(string& str) {
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
    
    int tc;
    cin >> tc;
    while (tc--) {
        string str;
        cin >> str;
        cout << (check(str) ? "YES" : "NO") << '\n';
    }
    
    return 0;
}


