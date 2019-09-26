// BOJ 1788 - 피보나치 수의 확장
#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int judge = 1;
    if (n < 0) {
        if (abs(n) % 2 == 0) {
            judge = -judge;
        }
    } else if (n == 0) {
        judge = 0;
    }
    
    n = abs(n);
    
    vector<long long> dp(n+1);
    for (int i = 0; i <= n; i++) {
        if (i < 2) {
            dp[i] = i % MOD;
            continue;
        }
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    
    cout << judge << '\n';
    cout << dp[n] << '\n';
    return 0;
}
