// BOJ 2909 - 캔디 구매
// 캔디의 가격을 상근이가 가진 금액으로 나눈다.
// 그 몫에 다시 상근이가 가진 금액을 곱하면 반올림하는데 사용할 수 있는 금액이 나온다.
// 상근이가 가진 금액의 절반보다(price / 2), 사탕가격에서 상근이가 가진 금액을 나눈 나머지(c % price)가
// 더 크거나 같다면 반올림 수에 상근이 가격을 더한다. (c = tc + price)
// 그게 아니라면 반올림 수를 반환한다.
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int c, k;
    cin >> c >> k;
    
    int price = 1;
    while (k--) {
        price *= 10;
    }
    
    // 반올림 하는데 사용하는 수를 구한다.
    int tc = (c / price) * price;
    
    if (price / 2 <= c % price) {
        c = tc + price;
    } else {
        c = tc;
    }
    
    cout << c << '\n';
    return 0;
}
