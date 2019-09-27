// BOJ 1188 - 음식 평론가
// 해결 방법이 떠오르지 않아서 블로그를 참고했다.
// 평론가들은 N/M 만큼 소시지를 동등하게 가져갈 수 있다.
// 여기서 내가 생각하지 못한 부분이 있는데
// N개의 소시지를 붙여놓고 M-1번의 칼질을 하면 정답을 구할 수 있다는 것이다.
// 그런데 N과 M이 나누어 떨어지면, 칼질이 전혀 필요없다.
// 따라서 M - GCD(N, M)의 공식으로 문제를 해결할 수 있다.
#include <iostream>

using namespace std;

int GCD1(int a, int b) {
    if (a % b == 0) return b;
    return GCD1(b, a % b);
}

int GCD2(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    cout << m - GCD1(n, m) << '\n';
    
    return 0;
}
