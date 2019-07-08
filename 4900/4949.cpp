// BOJ 4949 - 균형잡힌 세상
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while (true) {
        string str;
        getline(cin, str);
        
        // 종료 조건..!
        if (str.length() == 1 && str[0] == '.')
            break;
        
        bool flag = true;
        stack<char> st;
        for (char ch : str) {
            if (ch == '(') {
                st.push('(');
            } else if (ch == '[') {
                st.push('[');
            } else if (ch == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    flag = false;
                    break;
                }
            } else if (ch == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                } else {
                    flag = false;
                    break;
                }
            }
        }
        
        if (flag && st.empty()) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
    
    return 0;
}
