// BOJ 9020 - 골드바흐의 추측
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    const int MAX = 10000;
    vector<bool> isPrimeNum(MAX, true);
    for (int i = 2; i < sqrt(MAX); i++) {
        if (!isPrimeNum[i]) continue;
        for (int j = i*i; j <= MAX; j+=i) {
            if (!isPrimeNum[j]) continue;
            isPrimeNum[j] = false;
        }
    }
    
    int tc;
    cin >> tc;
    while (tc--) {
        int num;
        cin >> num;
        
        for (int i = num/2; i > 0; i--) {
            int left = i, right = num - i;
            if (isPrimeNum[left] && isPrimeNum[right]) {
                cout << left << " " << right << '\n';
                break;
            }
        }
    }
    
    return 0;
}

