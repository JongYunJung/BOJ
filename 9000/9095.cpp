// BOJ 9095 - 1, 2, 3 더하기
// 정수 4의 합을 1, 2, 3으로 나타내는 방법이 몇가지인가?
// 합이 1,
// 1
// -> 1개
// 합이 2,
// 1 + 1
// 2
// -> 2개
// 합이 3,
// 1 + 1 + 1
// 1 + 2
// 2 + 1
// 3
// -> 4개
// 합이 4,
// 1 + 1 + 1 + 1
// 1 + 1 + 2
// 1 + 2 + 1
// 1 + 3
// 2 + 1 + 1
// 2 + 2
// 3 + 1
// -> 7개
// 자세히 살펴보면 이전의 결과 값을 가지고, 현재의 값을 구할 수 있다.
// 예를 들면,
// dp[i] : 합의 i일때 나오는 결과
// dp[0] = 1이라고 무조건 지정해둔다.
// ( 양수이므로 n이 0일 수도 있는데 그때 합은 0, 갯수는 1이기 때문에 )
// i = 1,
// 1
// ----> 1개, dp[1] = { 1 }
// i = 2,
// (1) + 1
// 2
// ----> 2개, dp[2] = { 1+1, 2 }
// i = 3,
// (1 + 1) + 1, (2) + 1 (2)
// (1) + 2 (1)
// 3 (1)
// ----> 4개, dp[3] = { 1+1+1, 2+1, 1+2, 3 }
// i = 4,
// (1 + 1 + 1) + 1, (1 + 2) + 1, (2 + 1) + 1, (3) + 1 (4)
// (1 + 1) + 2, (2) + 2 (2)
// (1) + 3 (1)
// ----> 7개, dp[4] = { 1+1+1+1, 1+2+1, 2+1+1, 3+1, 1+1+2, 2+2, 1+3 }
#include <iostream>
#include <cstring>

using namespace std;

int dp[11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        int n;
        cin >> n;
        
        memset(dp, 0, sizeof(dp));
        
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (i - 1 >= 0) dp[i] += dp[i - 1];
            if (i - 2 >= 0) dp[i] += dp[i - 2];
            if (i - 3 >= 0) dp[i] += dp[i - 3];
        }
        
        cout << dp[n] << '\n';
    }
    
    return 0;
}
