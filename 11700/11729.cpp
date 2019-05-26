// BOJ 11729 - 하노이 탑 이동 순서
#include <iostream>
#include <cmath>
using namespace std;

void go(int n, int from, int by, int to) {
    if (n == 1) {
        cout << from << " " << to << '\n';
    } else {
        go(n-1, from, to, by);
        cout << from << " " << to << '\n';
        go(n-1, by, from, to);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int cnt = pow(2, n);
    cout << cnt - 1 << '\n';
    go(n, 1, 2, 3);
    
    return 0;
}
