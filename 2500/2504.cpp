// BOJ 2504 - 괄호의 값
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    cin >> str;
    
    stack<char> st;
    int temp = 1;
    long long answer = 0;
    bool impossible = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            st.push('(');
            temp *= 2;
        } else if (str[i] == '[') {
            st.push('[');
            temp *= 3;
        } else if (str[i] == ')' && (st.empty() || st.top() != '(')) {
            impossible = true;
            break;
        } else if (str[i] == ']' && (st.empty() || st.top() != '[')) {
            impossible = true;
            break;
        } else if (str[i] == ')') {
            if (str[i-1] == '(') answer += temp;
            temp /= 2;
            st.pop();
        } else if (str[i] == ']') {
            if (str[i-1] == '[') answer += temp;
            temp /= 3;
            st.pop();
        }
    }
    
    if (impossible || !st.empty()) {
        cout << 0 << '\n';
    } else {
        cout << answer << '\n';
    }
    
    return 0;
}
