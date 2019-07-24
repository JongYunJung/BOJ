// BOJ 2749 - 피보나치 수 3
#include <iostream>
#include <vector>

using namespace std;

int pisanoPeriod(int m) {
    int m1 = 0, m2 = 1, count = 0;
    do {
        int temp = m1;
        m1 = m2;
        m2 = (temp + m1) % m;
        count++;
    } while (m1 != 0 || m2 != 1);
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long n;
    cin >> n;
    
    const int MOD = 1e6;
    int period = pisanoPeriod(MOD);
    vector<int> cache(period + 1, 0);
    
    cache[1] = 1;
    for (int i = 2; i <= period; i++) {
        cache[i] = (cache[i-1] + cache[i-2]) % MOD;
    }
    
    cout << cache[n % period] << '\n';
    return 0;
}
