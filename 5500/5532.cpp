// BOJ 5532 - 방학 숙제
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;
    
    int l1 = a / c;
    
    if (a % c) l1++;
    
    int l2 = b / d;
    
    if (b % d) l2++;
    
    cout << l - max(l1, l2) << '\n';
    
    return 0;
}
