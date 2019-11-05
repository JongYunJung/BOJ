// BOJ 1850 - 최대공약수
// a 와 b 길이의 최대 공약수를 구한 다음 최대 공약수 만큼 1을 출력해주면 된다.
// teswt
#include <iostream>
#include <string>

using namespace std;

long long GCD(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long a, b;
    cin >> a >> b;
    
    long long gcd = (a < b) ? GCD(b, a) : GCD(a, b);
    cout << string(gcd, '1') << '\n';
    
    return 0;
}
