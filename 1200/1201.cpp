// BOJ 1201 - NMK
// 그리디 알고리즘
// 어려운 문제라서 정리해야할듯
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    if (m + k - 1 > n || n > m * k) {
        cout << -1 << '\n';
    } else {
        vector<int> arr(n);
        for (int i = 1; i <= n; i++) {
            arr[i-1] = i;
        }
        
        int idx = 0;
        for (int i = 1; i <= m; i++) {
            int temp = min(idx + k, n - m + i);
            reverse(arr.begin() + idx, arr.begin() + temp);
            idx = temp;
        }
        
        for (int num : arr) cout << num << " ";
        cout << '\n';
    }
    
    return 0;
}
