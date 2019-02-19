// BOJ 1208 - 2
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int m = n / 2;
    n -= m;
    
    vector<int> first(1<<n);
    for (int i = 0; i < (1<<n); i++) {
        for (int k = 0; k < n; k++) {
            if (i & (1<<k)) {
                first[i] += a[k];
            }
        }
    }
    
    vector<int> second(1<<m);
    for (int i = 0; i < (1<<m); i++) {
        for (int k = 0; k < m; k++) {
            if (i & (1<<k)) {
                second[i] += a[n+k];
            }
        }
    }
    
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    reverse(second.begin(), second.end());
    
    n = (1 << n);
    m = (1 << m);
    int i = 0, j = 0;
    long long cnt = 0;
    while (i < n && j < m) {
        if (first[i] + second[j] == s) {
            long long c1 = 1;
            long long c2 = 1;
            
            i++;
            j++;
            
            while (i < n && first[i] == first[i-1]) {
                c1++;
                i++;
            }
            
            while (j < m && second[j] == second[j-1]) {
                c2++;
                j++;
            }
            
            cnt += (c1 * c2);
        } else if (first[i] + second[j] < s) {
            i++;
        } else  {    // first[i] + second[j] > s
            j++;
        }
    }
    
    if (s == 0)
        cnt -= 1;
    
    cout << cnt << '\n';
    return 0;
}
