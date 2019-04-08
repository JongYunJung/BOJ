// BOJ 1024 - 수열의 합
// 쉬운 문제인줄 알았지만 생각보다 어려웠다.
// https://danco.tistory.com/30 -> 블로그 참고하여 구현했음
#include <iostream>
using namespace std;
const int MAX_LEN = 100;

int sumOfSeq(int n) {
    return n * (n + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, l;
    cin >> n >> l;
    
    // 수학 공식을 알면 간단히 해결되는 문제였다..
    // n = x + (x + 1) + (x + 2) + .. + (x + (l-1))
    // n = l * x + (1 + 2 + ... + (l-1))
    // (1 + 2 + ... + (l-1)) 되는 과정을 t 라고 한다면
    // n = l * x + t
    // x = (n - t) / l
    // 위와 같은 공식으로 시작하는 숫자인 x 를 구할 수 있다.
    // 필수 조건 x >= 0 이어야 하고 (n - t) / l 의 나머지는 0 이어야 한다.
    while (l <= MAX_LEN) {
        int x = (n - sumOfSeq(l-1)) / l;
        int m = (n - sumOfSeq(l-1)) % l;
        if (x >= 0 && m == 0) {
            while (l--) {
                cout << x << " ";
                ++x;
            }
            cout << '\n';
            return 0;
        }
        ++l;
    }
    
    cout << -1 << '\n';
    return 0;
}
