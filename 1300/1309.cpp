// BOJ - 1309 동물원
// DP 문제인데 점화식 세우는게 너무 더럽다..
#include <iostream>
using namespace std;
int dp[3][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    const int mod = 9901;
    // 0 : 사자를 놓지 않는 경우, 1: 사자를 왼쪽에 놓는 경우, 2: 사자를 오른쪽에 놓는 경우
    dp[0][1] = dp[1][1] = dp[2][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[0][i] = (dp[0][i-1] + dp[1][i-1] + dp[2][i-1]) % mod;
        dp[1][i] = (dp[0][i-1] + dp[2][i-1]) % mod;
        dp[2][i] = (dp[0][i-1] + dp[1][i-1]) % mod;
    }
    
    cout << (dp[0][n] + dp[1][n] + dp[2][n]) % mod << '\n';
    return 0;
}

