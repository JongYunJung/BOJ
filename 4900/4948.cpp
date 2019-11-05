// BOJ 4948 - 베르트랑 공준
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    const int MAX_N = 2 * 123456 + 1;
    vector<bool> isPrimeNum(MAX_N, true);
    for (int i = 2; i < sqrt(MAX_N); i++) {
        if (!isPrimeNum[i]) continue;
        for (int j = i*i; j <= MAX_N; j+=i) {
            if (!isPrimeNum[j]) continue;
            isPrimeNum[j] = false;
        }
    }
    
    while (true) {
        int n;
        cin >> n;
        
        if (n == 0) break;
        
        int primeNumCount = 0;
        for (int i = n+1; i <= 2*n; i++) {
            if (isPrimeNum[i]) primeNumCount++;
        }
        
        cout << primeNumCount << '\n';
    }
    
    return 0;
}

