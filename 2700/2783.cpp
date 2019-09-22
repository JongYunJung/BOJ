// BOJ 2783 - 삼각 김밥
// 그냥 요구한대로 구현하면 된다.
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    double x, y;
    cin >> x >> y;
    
    double minCost = x / y * 1000;
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double tx, ty;
        cin >> tx >> ty;
        if (minCost > tx / ty * 1000) {
            minCost = tx / ty * 1000;
        }
    }
    
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << minCost << '\n';
    return 0;
}
