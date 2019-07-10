// BOJ 5430 - AC
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        string p;
        cin >> p;
        
        int n;
        cin >> n;
        
        string arr;
        cin >> arr;
        
        deque<int> dq;
        string temp = "";
        for (char ch : arr) {
            if (ch == '[') continue;
            if ('0' <= ch && ch <= '9') temp += ch;
            else if (ch == ',' || ch == ']') {
                if (!temp.empty()) {
                    dq.push_back(stoi(temp));
                    temp.clear();
                }
            }
        }
        
        bool left = true;
        bool isNotError = true;
        for (char ch : p) {
            if (ch == 'R') {
                left = !left;
            } else {
                if (dq.empty()) {
                    cout << "error" << '\n';
                    isNotError = false;
                    break;
                } else (left) ? dq.pop_front() : dq.pop_back();
            }
        }
        
        if (isNotError) {
            cout << "[";
            while (!dq.empty()) {
                if (left) {
                    cout << dq.front();
                    dq.pop_front();
                } else {
                    cout << dq.back();
                    dq.pop_back();
                }
                if (!dq.empty()) cout << ",";
            }
            cout << "]" << '\n';
        }
    }
    
    return 0;
}
