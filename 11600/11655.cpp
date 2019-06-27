// BOJ 11655 - ROT13
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    getline(cin, s);
    // mod..
    for (char ch : s) {
        if (('0' <= ch && ch <= '9') || ch == ' ') {
            cout << ch;
        } else if (('a' <= ch && ch <= 'a' + 12) || ('A' <= ch && ch <= 'A' + 12)) {
            cout << (char)(ch + 13);
        } else {
            cout << (char)(ch - 13);
        }
    }
    cout << '\n';
    
    return 0;
}
