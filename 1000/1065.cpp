// BOJ 1065 - 한수
// 1 자리 수는 뒤에 수가 없기 때문에 등차수열 성립
// 2 자리 수는 숫자 차이가 어떻게 나더라도 세 번째 수가 없기때문에 등차수열이 성립
// 1 ~ 99 한수가 된다.
// 3 자리 수 부터 한수를 찾아주면 된다.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    if (n < 100) {
        cout << n << '\n';
    } else {
        int ans = 99;
        for (int num = 100; num <= n; num++) {
            int hDigit = num / 100;
            int tDigit = (num / 10) % 10;
            int uDigit = num % 10;
            
            if (uDigit - tDigit == tDigit - hDigit) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}

