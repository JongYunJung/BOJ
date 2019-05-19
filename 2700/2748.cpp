// BOJ 2748 - 피보나치 수 2
#include <iostream>
#include <cstring>
using namespace std;

long long cache[91];

long long fibo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (cache[n] != -1) return cache[n];
    return cache[n] = fibo(n-1) + fibo(n-2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    cout << fibo(n) << '\n';
    
    return 0;
}
