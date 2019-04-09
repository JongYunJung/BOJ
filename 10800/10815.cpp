// BOJ 10815 - 숫자 카드
// 이분 탐색
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int m;
    cin >> m;
    sort(a.begin(), a.end());
    while (m--) {
        int v;
        cin >> v;
        
        bool find = false;
        int l = 0, r = (int)a.size()-1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (a[m] > v) {
                r = m - 1;
            } else if (a[m] < v) {
                l = m + 1;
            } else {
                find = true;
                break;
            }
        }
        
        cout << find << '\n';
    }
    
    return 0;
}
