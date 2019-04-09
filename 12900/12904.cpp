// BOJ - 12904 A와 B
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// T에서 S를 만들 수 있는지 보는 문제
// T의 마지막 문자가 B면 B를 제거하고 앞을 뒤집고
// T의 마지막 문자가 A면 그냥 제거
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s, t;
    cin >> s >> t;
    while (t.length() > s.length()) {
        size_t last = t.length()-1;
        if (t[last] == 'A') {
            t.pop_back();
        } else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    
    if (t == s) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
    
    return 0;
}
