// BOJ 1049 - 기타줄
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int minPackage = 1000, minUnit = 1000;
    for (int i = 0; i < m; i++) {
        int package, unit;
        cin >> package >> unit;
        minPackage = min(minPackage, package);
        minUnit = min(minUnit, unit);
    }
    
    int ans = 0;
    while (n > 0) {
        if (n - 6 >= 0 && minPackage > minUnit * 6) {
            ans += minUnit * 6;
        } else if (n - 6 < 0 && minPackage > minUnit * n){
            ans += minUnit * n;
        } else {
            ans += minPackage;
        }
        n -= 6;
    }
    
    cout << ans << '\n';
    return 0;
}
