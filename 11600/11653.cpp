// BOJ 11653 - 소인수분해
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<bool> isPrime(n+1, true);
    for (int i = 2; i < sqrt(n); i++) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= n; j+=i) {
            if (!isPrime[j]) continue;
            isPrime[j] = false;
        }
    }
    
    vector<int> primeNum;
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        primeNum.push_back(i);
    }
    
    vector<int> ans;
    for (int i = 0; i < primeNum.size(); i++) {
        int temp = n;
        while (temp % primeNum[i] == 0) {
            ans.push_back(primeNum[i]);
            temp /= primeNum[i];
        }
        if (temp == 1) break;
    }
    
    for (int num : ans) cout << num << '\n';
    
    return 0;
}
