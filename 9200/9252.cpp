// BOJ 9252 - LCS 2
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str1, str2;
    cin >> str1 >> str2;
    
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
    
    vector<char> ans;
    int i = (int)str1.length();
    int j = (int)str2.length();
    
    while (i >= 1 && j >= 1) {
        if (dp[i][j] == dp[i][j-1]) {
            j--;
        } else if (dp[i][j] == dp[i-1][j]) {
            i--;
        } else {
            ans.push_back(str1[i-1]);
            i--;
            j--;
        }
    }
    
    for (int i = (int)ans.size()-1; i >= 0; i--) {
        cout << ans[i];
    }
    
    cout << '\n';
    return 0;
}

