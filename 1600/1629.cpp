// BOJ 1629 곱셈
#include <iostream>
using namespace std;

long long cal(long long a, long long b, long long c) {
    // 예외처리.. a^0 => 1
    if (b == 0) {
        return 1LL;
    // a^1 => a
    } else if (b == 1) {
        return a%c;
    // 짝수인 경우에는..
    } else if (b % 2 == 0) {
        // 만약에 return cal(a, b/2) * cal(a, b/2) 을 하면
        // 호출이 2배가 되므로 O(N) 이 걸린다.
        // cal(a, b/2)의 한번의 결과로 ans * ans 해주는게 효율적
        long long ans = cal(a, b/2, c);
        return (ans * ans) % c;
    // 홀수인 경우에는..
    } else { // b % 2 == 1
        return (a * cal(a, b-1, c)) % c;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    // 분할 정복을 이용해서 구할수 있다.
    // a^2b = a^b x a^b
    // a^(2b+1) = a x a^2b
    // b 가 짝수이면 b/2
    // b 가 홀수이면 1 그리고 b-1
    cout << cal(a, b, c) << '\n';
    return 0;
}
