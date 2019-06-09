// BOJ 10872 - 팩토리얼
#include <iostream>
using namespace std;

int fact(int n) {
    if (n < 2) return 1;
    return n * fact(n-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    cout << fact(n) << '\n';
    
    return 0;
}
