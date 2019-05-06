// BOJ 2565 - 전깃줄
// DP를 사용한 방식
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100;
pair<int, int> p[MAX];
int dp[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p+n);
    
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (p[i].second > p[j].second && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    
    cout << n - ans << '\n';
    return 0;
}

