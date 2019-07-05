// BOJ 2312 - 수 복원하기
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        // 인수를 구하는 방식으로 해결..!
        for (int i = 2; i <= n; i++) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            // cnt가 0이 아닐때만 출력하도록..
            // 그렇게 하지 않으면 '출력 초과' 발생함..
            if (cnt) cout << i << " " << cnt << '\n';
        }
    }
    
    return 0;
}
