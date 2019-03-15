// BOJ 1010 - 다리 놓기
// 다이나믹 프로그래밍 (DP) 방식으로 해결
// n 이 1개 인 경우..
// m 의 개수 만큼 dp[1][?] = ? 형태의 경우의 수를 저장한다.
// n 이 2개 이상인 경우..
// dp[i][j] = dp[i-1][j-1] (i-1 사이트 일때, 나온 경우의 수) + dp[i][j-1] (i 사이트 일때, 나온 경우의 수)
// 위와 같은 점화식을 이용하면 현재 경우의 수를 구할 수 있다.
#include <iostream>
#include <cstring>
using namespace std;
long long dp[31][31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        memset(dp, 0, sizeof(dp));
        
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= m; i++) dp[1][i] = i;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            }
        }
        
        cout << dp[n][m] << '\n';
    }
    
    return 0;
}
