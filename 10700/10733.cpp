// BOJ 10773 - 제로
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    stack<int> st;
    while (n--) {
        int value;
        cin >> value;
        
        if (!st.empty() && value == 0) {
            st.pop();
            continue;
        }
        
        st.push(value);
    }
    
    long long answer = 0;
    while (!st.empty()) {
        answer += st.top();
        st.pop();
    }
    cout << answer << '\n';
    
    return 0;
}
