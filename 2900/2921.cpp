// BOJ 2921 - 도미노
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= 2*i; j++) {
            sum += j;
        }
    }
    
    cout << sum << '\n';
    return 0;
}
