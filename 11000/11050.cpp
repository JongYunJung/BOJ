// BOJ 11050 - 이항 계수 1
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    int nn = 1;
    for (int num = n; num > n - k; num--) {
        nn *= num;
    }
    
    int kk = 1;
    for (int num = 2; num <= k; num++) {
        kk *= num;
    }
    
    cout << nn / kk << '\n';
    return 0;
}
