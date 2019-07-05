// BOJ 2312 - 수 복원하기
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        // 소인수를 구하는 방식..
        for (int i = 2; i * i <= n; i++) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            // cnt 가 0이 아닐때 출력하도록 한다.
            // 처리를 해주지 않으면 '출력 초과' 난다.
            if (cnt) cout << i << " " << cnt << '\n';
        }
        // n == 1 인 경우에는 pass..
        if (n > 1) cout << n << " " << 1 << '\n';
    }
    
    return 0;
}
