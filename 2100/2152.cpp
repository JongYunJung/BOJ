// BOJ 2011 - 암호 코드
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int mod = 1000000;
int dp[5001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int n = (int)s.length();
    vector<int> nums(n+1);
    for (int i = 1; i <= n; i++) {
        nums[i] = s[i-1] - '0';
    }
    
    if (n == 1 && s[0] == '0') {
        cout << 0 << '\n';
        return 0;
    }
    
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (nums[i] > 0) {
            dp[i] = dp[i-1] % mod;
            if (i == 1) continue;
        }
        
        int x = nums[i-1] * 10 + nums[i];
        if (10 <= x && x <= 26) {
            dp[i] = (dp[i] + dp[i-2]) % mod;
        }
    }
    
    cout << dp[n] << '\n';
    return 0;
}
