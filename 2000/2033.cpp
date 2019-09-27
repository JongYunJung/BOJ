// BOJ 2033 - 반올림
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int multipleOfTen = 10;
    while (n > multipleOfTen) {
        // 반올림을 체크할 때 자리 수를 생각해야 하는데
        // ex)
        // 5 >= 5
        // 50 >= 50
        // 500 >= 500
        // 이런식으로 비교하면 수월하게 반올림을 체크할 수 있다.
        if (n % multipleOfTen >= 5 * (multipleOfTen / 10)) {
            n += multipleOfTen;
        }
        n -= n % multipleOfTen;
        multipleOfTen *= 10;
    }
    
    cout << n << '\n';
    return 0;
}
