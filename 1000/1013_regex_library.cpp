// BOJ 1013 - Contact
// 정규 표현식 관련된 문제
#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        string str;
        cin >> str;
        regex re("(100+1+|01)+");
        cout << (regex_match(str, re) ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
