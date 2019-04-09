// BOJ 2805 - 나무 자르기
// 이분 탐색
// 이분 탐색을 통해 중간 지점은 현재 절단기에서 설정할 수 있는 높이가 된다.
// N 만큼 나무를 자르고 난 뒤의 합을 통해 이분 탐색할 위치를 정하면 된다.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    long long left = 0;
    long long right = *max_element(a.begin(), a.end());
    
    long long ans = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mid) sum += a[i] - mid;
        }
        if (sum >= m) {
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
