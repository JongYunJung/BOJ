// BOJ 2631 - 줄세우기
// LIS 문제
// O(n^2) 방식 - DP
// 문제에서 핵심은 '다시 번호 순서대로 줄을 세우기 위해서 아이들의 위치를 옮기려고 한다.'
// 오름차순 정렬을 하는 것인데 정렬하면서 움직이는 횟수를 최소화 해야한다.
// 왜 LIS 알고리즘이 적용되는가?
// 이유는 부분적으로 증가하고 있는 번호를 가진 아이들을 기준으로 잡고
// 아이들을 옮기는 것이 최소화 할 수 있다고 한다.
// O(NlogN) 방식으로도 해결 가능
#include <iostream>
#include <vector>
using namespace std;
int dp[200];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    
    cout << n - ans << '\n';
    return 0;
}
