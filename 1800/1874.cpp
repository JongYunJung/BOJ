// BOJ 1874 - 스택 수열
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<char> answer;
    stack<int> st;
    int num = 1;
    for (int i = 0; i < n; i++) {
        if (st.empty() || st.top() != arr[i]) {
            while (true) {
                if (num > n) {
                    cout << "NO" << '\n';
                    return 0;
                }
                st.push(num++);
                answer.push_back('+');
                if (st.top() == arr[i]) {
                    answer.push_back('-');
                    st.pop();
                    break;
                }
            }
        } else if (!st.empty() && st.top() == arr[i]) {
            answer.push_back('-');
            st.pop();
        }
    }
    
    for (char ch : answer) cout << ch << '\n';
    
    return 0;
}

