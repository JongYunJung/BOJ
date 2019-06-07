// BOJ 10799 - 쇠막대기
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    stack<char> st;
    int answer = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push('(');
        else {
            st.pop();
            if (s[i-1] == '(') answer += st.size();
            else answer += 1;
        }
    }
    
    cout << answer << '\n';
    return 0;
}
