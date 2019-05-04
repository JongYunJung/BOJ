// BOJ 9507 - Generations of Tribbles
// 재귀 호출로 구현해봤음..
#include <iostream>
using namespace std;
const int MAX = 67;
long long dp[MAX+1];

long long go(int n) {
    if (n < 2)  return dp[n] = 1;
    if (n == 2) return dp[n] = 2;
    if (n == 3) return dp[n] = 4;
    if (dp[n] != 0) return dp[n];
    return dp[n] = go(n-1) + go(n-2) + go(n-3) + go(n-4);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    go(MAX);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    
    return 0;
}
