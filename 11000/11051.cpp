// BOJ 11051 - 이항 계수 2
#include <iostream>
using namespace std;
const int mod = 10007;
int d[1001][1001];

// 다이나믹 프로그래밍으로 해결
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    d[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        d[i][0] = d[i][i] = 1;
        for (int j = 1; j <= i-1; j++) {
            d[i][j] = d[i-1][j-1] + d[i-1][j];
            d[i][j] %= mod;
        }
    }
    
    cout << d[n][k] << '\n';
    return 0;
}
