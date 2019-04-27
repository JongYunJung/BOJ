// BOJ 1915 - 가장 큰 정사각형
// DP 문제를 파악하고 점화식을 세우려고 했으나 그러지 못했다.
// 블로그를 참고하여 해결했다.

// 풀이 도중 의문점이 드는 것을 정리했음...
// 3방향 중에서 min 값을 구하는 이유?
// dp[i-1][j-1] = 3, dp[i-1][j] = 4, dp[i][j-1] = 2 라고 한다면,
// dp[i][j] 에서 정사각형을 만들면 길이가 3인 경우와 4인 경우는 길이가 2인 경우를 포함하고 있지 않기 때문에
// 가장 작은 값으로 현재 값을 갱신해야 한다. (정확하게 설명하려면 그림을 그려야 한다.)
// 1을 더해주는 이유?
// 이전 정사각형 길이의 +1 을 더해줘야 하기 때문
// i, j 가 0일수도 있는데 이전 정사각형 길이의 +1을 더해줘야 하는걸까?
// a[i][j] 가 0 이건 1 이건 간에 'dp[i][j]' 길이를 메모이제이션 하고 있기 때문에
// 무조건 a[i][j] 가 1이라고 생각하고 진행하는 것이다.
// 즉, a[i][j] = 0 이어도 길이는 1을 가진 정사각형이기 때문이다.
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int dp[1001][1001];
int a[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            dp[i][j] = a[i][j] = s[j] - '0';
        }
    }
    
    // n = 1, m = 1 인 경우가 있기 때문에 dp[0][0] 으로 초기화
    // a[0][0] 이 0 이거나 1 인 경우가 있기 때문에
    // 무조건으로 ans_len 1 이 아니다. -> 이것때문에 많이 틀림
    int ans_len = dp[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i-1][j] == 1 && a[i-1][j-1] == 1 && a[i][j-1] == 1) {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]);
                dp[i][j] = min(dp[i][j], dp[i][j-1]) + 1;
            }
            ans_len = max(ans_len, dp[i][j]);
        }
    }
    
    cout << ans_len * ans_len << '\n';
    return 0;
}
