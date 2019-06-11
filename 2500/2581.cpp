// BOJ 2581 - 소수
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 10000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<bool> isPrimeNum(MAX+1, true);
    isPrimeNum[1] = false;
    for (int i = 2; i < sqrt(MAX); i++) {
        if (!isPrimeNum[i]) continue;
        for (int j = i*i; j <= MAX; j+=i) {
            isPrimeNum[j] = false;
        }
    }
    
    int m, n;
    cin >> m >> n;
    
    int minValue = 0, primeSum = 0;
    for (int i = m; i <= n; i++) {
        if (isPrimeNum[i]) {
            if (minValue == 0) minValue = i;
            primeSum += i;
        }
    }
    
    if (minValue == 0 && primeSum == 0) {
        cout << -1 << '\n';
    } else {
        cout << primeSum << '\n';
        cout << minValue << '\n';
    }
    
    return 0;
}
