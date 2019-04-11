// BOJ 2163 - 초콜릿 자르기
#include <iostream>
#include <cstring>
using namespace std;
int dp[301];

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, 0, sizeof(dp));
    
    int n, m;
    cin >> n >> m;
    
    // n-1은 크기가 n인 초콜릿을 잘랐을때 경우의 수
    dp[1] = n-1;
    for (int i = 2; i <= m; i++) {
        // n-1은 크기가 n인 초콜릿을 잘랐을때 경우의 수
        // 1 은 더해준 이유? 현재 크기에서 무조건 1번을 잘라줘야 하기 때문에
        // dp[i] = dp[i-1] + n; 으로 해도 무방
        dp[i] = dp[i-1] + (n-1) + 1;
    }
    
    cout << dp[m] << '\n';
    return 0;
}

