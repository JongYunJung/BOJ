// BOJ 14003 - 가장 긴 증가하는 부분 수열 5
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    pair<int, int> ans[n];
    vector<int> lis(n);
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        int target;
        cin >> target;
        
        if (i == 0) {
            lis[i] = target;
            ans[i].first  = 0;
            ans[i].second = target;
            continue;
        } else {
            if (lis[j] < target) {
                lis[++j] = target;
                ans[i].first = j;
                ans[i].second = target;
            } else {
                int left = 0, right = j;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (lis[mid] < target) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                lis[right] = target;
                ans[i].first = right;
                ans[i].second = target;
            }
        }
    }
    
    cout << j + 1 << '\n';
    
    int t = j;
    stack<int> st;
    for (int i = n-1; i >= 0; i--) {
        if (ans[i].first == t) {
            st.push(ans[i].second);
            t--;
        }
    }
    
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    
    cout << '\n';
    return 0;
}

