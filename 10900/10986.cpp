// BOJ 10986 - 나머지 합
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // 연속된 구간의 합이 m으로 나누어 떨어지려면
    // (s[j] - s[i-1]) % m == 0 이 나와야 하는데
    // 이런 방식은 O(n^2) 의 시간 복잡도가 걸린다.
    // 따라서 s[j] % m == s[i-1] % m 인 점을 이용하여
    // 해당 값을 나눈 나머지를 저장할 cnt 배열을 만든다.
    vector<long long> cnt(m);
    cnt[0] = 1; // 항상 구간합의 s[0] = 0 이므로.. 0의 값을 +1 해준다.
    int sum = 0;
    for (int i = 0; i < n; i++) {
        // 구간합을 구하고 m으로 나눈 나머지를 구한다.
        sum += a[i];
        sum %= m;
        // sum 이 m으로 나눈 나머지 0,1,2,..,m-1 값을 가지고 있는데
        // 해당 나머지 값의 위치를 증감시킨다.
        ++cnt[sum];
    }
    
    // cnt 배열을 이용하여 나올수 있는 경우의 수 구하기
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans += (cnt[i] * (cnt[i]-1)) / 2LL;
    }
    
    cout << ans << '\n';
    return 0;
}
