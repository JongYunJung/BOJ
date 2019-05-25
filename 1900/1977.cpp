// 1977 BOJ - 완전 제곱수
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    
    int minNum = 0, sum = 0;
    int squareNum = 0, num = 1;
    while ((squareNum = num * num) <= n) {
        if (squareNum >= m) {
            sum += squareNum;
            if (minNum == 0) minNum = squareNum;
        }
        ++num;
    }
    
    if (sum == 0) {
        cout << -1 << '\n';
    } else {
        cout << sum << '\n';
        cout << minNum << '\n';
    }
    
    return 0;
}
