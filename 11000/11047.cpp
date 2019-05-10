// BOJ 11047 - 동전0
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        if (k < a[i]) continue;
        ans += (k / a[i]);
        k %= a[i];
    }
    
    cout << ans << '\n';
    return 0;
}

