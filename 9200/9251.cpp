// BOJ 9251 - LCS
// 문제를 파악했으나 구현하는 부분에서 틀렸음
// 구현을 너무 어렵게 생각함..
// 단순하게 구현하면 되는데
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str1;
    cin >> str1;
    
    string str2;
    cin >> str2;
    
    memset(dp, 0, sizeof(dp));
    int n = (int)str1.length();
    int m = (int)str2.length();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    cout << dp[n][m] << '\n';
    return 0;
}

