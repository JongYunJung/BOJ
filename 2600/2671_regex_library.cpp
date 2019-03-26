// BOJ 2671 - 잠수함 식별 (1013 Contact 문제와 동일)
// 정규화 문제
#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    regex re("(100+1+|01)+");
    string str;
    cin >> str;
    cout << (regex_match(str, re) ? "SUBMARINE" : "NOISE") << '\n';
    
    return 0;
}
