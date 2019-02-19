// BOJ 1107
#include <iostream>
#include <cmath>
using namespace std;
bool broken[10];
int possible(int c) {
    if (c == 0) {
        return (broken[c]) ? 0 : 1;
    }
    
    int len = 0;
    while (c > 0) {
        if (broken[c % 10]) {
            return 0;
        }
        c /= 10;
        len++;
    }
    
    return len;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int btn;
        cin >> btn;
        broken[btn] = true;
    }
    
    int ans = abs(n - 100);
    for (int c = n; c <= 1000000; c++) {
        int len = possible(c);
        if (len > 0) {
            int press = c - n + len;
            ans = (ans > press) ? press : ans;
            break;
        }
    }
    
    for (int c = n; c >= 0; c--) {
        int len = possible(c);
        if (len > 0) {
            int press = n - c + len;
            ans = (ans > press) ? press : ans;
            break;
        }
    }
    
    cout << ans << '\n';
    return 0;
}

