// BOJ 9471 - 피사노 주기
#include <iostream>

using namespace std;

int pisanoPeriod(int m) {
    int m1 = 0, m2 = 1, count = 0;
    do {
        int temp = m1;
        m1 = m2;
        m2 = (temp + m1) % m;
        count++;
    } while (m1 != 0 || m2 != 1);
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        cout << n << " " << pisanoPeriod(m) << '\n';
    }
    
    return 0;
}
