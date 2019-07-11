// BOJ 1351 - 무한 수열
// 첫 번째는 bottom-up 방식으로 풀었는데 '메모리 초과'가 났다.
// Top-Down 방식으로 풀어서 "이미 값을 가지고 있다면 리턴하는 방법"을 사용했다.
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> dp;
long long n, p, q;

long long go(long long i) {
    if (i == 0) return dp[0] = 1;
    if (dp.count(i)) return dp[i];
    return dp[i] = go(i / p) + go(i / q);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> p >> q;
    cout << go(n) << '\n';
    
    return 0;
}
