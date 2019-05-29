// BOJ 2443 - 별 찍기 - 6
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < n-i; j++) cout << " ";
        for (int j = 0; j < 2*i-1; j++) cout << "*";
        cout << '\n';
    }
    
    return 0;
}
