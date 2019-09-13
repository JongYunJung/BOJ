// BOJ 3053 - 택시 기하학
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    const double pi = 3.14159265358979;
    
    double r;
    cin >> r;
    
    cout << fixed;
    cout.precision(6);
    cout << r * r * pi << '\n';
    cout << r * r * 2 << '\n';
    
    return 0;
}
