// BOJ 2133 - 타일 채우기
// n 이 4 이상인 경우 부터 +2 특수한 경우가 추가 된다.
// dp[2] = 3;
// dp[4] = dp[2] * 3 + (2)                                      => 특수한 경우 2가 추가 된다.
// dp[6] = dp[4] * 3 + dp[2] * 2 + dp[0] * 2 + (2)              => 특수한 경우 2가 추가 된다.
// dp[8] = dp[6] * 3 + dp[4] * 2 + dp[2] * 2 + dp[0] * 2 + (2)  => 특수한 경우 2가 추가 된다.
// 특수한 경우란 ?
// 2x1 타일을 가로로 n 길이를 채웠을 때
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int dp[31] = {1, 0 ,3};
    
    int n;
    cin >> n;
    
    if (n % 2 == 0) {
        for (int i = 4; i <= n; i+=2) {
            dp[i] = dp[i-2] * 3;
            
            for (int j = 4; j <= i; j+=2) {
                dp[i] += dp[i - j] * 2;
            }
        }
    }
    
    cout << dp[n] << '\n';
    return 0;
}

