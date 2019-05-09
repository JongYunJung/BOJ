// BOJ 11049 - 행렬 곱셈 순서
// dp문제 -> top down 방식으로..
// 큰 문제를 작은 문제로 나눠서 해결하는 방식
// 작은 문제의 리턴 값으로 전체 문제를 푼다.
// 이 문제에서는 현재 행렬 곱셈의 값을 구한 뒤, 2개의 부분 문제로 나눠서 풀어야 한다.
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX = 500;

pair<int, int> info[MAX];
int dp[MAX][MAX];

int go(int start, int end) {
    if (start == end)
        return 0;
    
    if (dp[start][end] != -1)
        return dp[start][end];
    
    int& ans = dp[start][end] = INF;
    for (int i = start; i < end; i++) {
        int now = info[start].first * info[i].second * info[end].second;
        ans = min(ans, go(start, i) + go(i+1, end) + now);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> info[i].first >> info[i].second;
    }
    
    memset(dp, -1, sizeof(dp));
    cout << go(0, n-1) << '\n';
    return 0;
}

