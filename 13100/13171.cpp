// BOJ 13171 - A
// a의 값을 x의 값이 0이 될때 까지 a = (a * a) % MOD 를 한다.
// x의 값을 이진수로 만드는 과정에서 이진수의 값이 1이면, answer = (answer * a) % MOD 를 한다.
#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long int a, x;
    cin >> a >> x;
    a %= MOD;
    
    long long int answer = 1;
    while (x != 0) {
        if (x % 2) answer = (answer * a) % MOD;
        a = (a * a) % MOD;
        x /= 2;
    }
    
    cout << answer << '\n';
    return 0;
}
