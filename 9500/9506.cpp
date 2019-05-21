// BOJ 9506 - 약수들의 합
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while (true) {
        int n;
        cin >> n;
        if (n == -1) break;
        
        vector<int> factor;
        int factor_sum = 0;
        for (int num = 1; num < n; num++) {
            if (n % num == 0) {
                factor.push_back(num);
                factor_sum += num;
            }
        }
        
        if (n == factor_sum) {
            cout << n << " = " << factor[0];
            for (int i = 1; i < factor.size(); i++) cout << " + " << factor[i];
            cout << '\n';
        } else cout << n << " is NOT perfect." << '\n';
    }
    
    return 0;
}
