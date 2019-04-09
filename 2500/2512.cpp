// BOJ 2512 - 예산
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    int left = 1, right = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        right = max(right, a[i]);
    }
    
    int m;
    cin >> m;
    
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= mid) sum += mid;
            else sum += a[i];
        }
        if (sum <= m) {
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
