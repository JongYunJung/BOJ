// BOJ 1654 - 랜선 자르기
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int k, n;
    cin >> k >> n;
    vector<long long> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];
    
    long long ans = 0;
    long long left = 0;
    long long right = LLONG_MAX;
    while (left <= right) {
        long long mid = (left + right) / 2;
        int lanCableCount = 0;
        for (int i = 0; i < k; i++) {
            lanCableCount += a[i] / mid;
        }
        if (lanCableCount >= n) {
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << ans << '\n';
    return 0;
}

// 두 번째 풀이
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int k, n;
    cin >> k >> n;
    
    vector<long long> arr(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    
    long long answer = 0;
    long long low = 1, high = *max_element(arr.begin(), arr.end());
    while (low <= high) {
        long long mid = (low + high) / 2;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += arr[i] / mid;
        }
        
        if (cnt >= n) {
            answer = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    
    cout << answer << '\n';
    return 0;
}
