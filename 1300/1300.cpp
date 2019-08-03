// BOJ 1300 - K번째 수
// 이분 탐색 문제..
// 굉장히 어렵다...!
// 2차원 배열을 1차원배열로 만들때, 오름차순을 해서 만든다.
// ( 2차원 배열 그대로의 순서가 아니라는 뜻 )
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    int answer = 0;
    int low = 1, high = k;
    while (low <= high) {
        // cnt : mid의 값보다 같거나 작은 값들의 갯수
        int cnt = 0;
        int mid = (low + high) / 2;
        for (int i = 1; i <= n; i++) {
            cnt += min(mid / i, n);
        }
        
        if (cnt >= k) {
            answer = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    
    cout << answer << '\n';
    return 0;
}
