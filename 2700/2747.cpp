// BOJ 2747 - 피보나치 수
// DP 방식으로 접근해서 해결
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> fibo(n+1);
    for (int i = 0; i <= n; i++) {
        if (i - 2 < 0) {
            fibo[i] = i;
            continue;
        }
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    
    cout << fibo[n] << '\n';
    return 0;
}
