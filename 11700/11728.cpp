// BOJ 11728 - 배열 합치기
// merge 개념으로 풀어봄
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    
    vector<int> ans;
    ans.reserve(n + m);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) ans.push_back(a[i++]);
        else ans.push_back(b[j++]);
    }
    
    while (i < n) ans.push_back(a[i++]);
    while (j < m) ans.push_back(b[j++]);
    
    for (int num : ans) cout << num << " ";
    cout << '\n';
    
    return 0;
}
