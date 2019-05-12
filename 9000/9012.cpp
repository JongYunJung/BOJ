// BOJ 9012 - 괄호
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkParenthesis(string str) {
    stack<char> st;
    
    for (char c : str) {
        if (c == '(') st.push(c);
        else if (c == ')') {
            if (!st.empty()) st.pop();
            else return false;
        }
    }
    
    return st.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        string str;
        cin >> str;
        cout << (checkParenthesis(str) ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
