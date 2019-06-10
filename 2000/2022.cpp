// BOJ 2022 - 사다리
// 수학 공식을 알아야한다.
// 이분 탐색을 이용해서 너비를 찾아야 한다.
#include <iostream>
#include <cmath>
using namespace std;

double getHeight(double x, double y, double mid) {
    double h1 = sqrt(x*x - mid*mid);
    double h2 = sqrt(y*y - mid*mid);
    return (h1 * h2) / (h1 + h2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    double x, y, c;
    cin >> x >> y >> c;
    
    double answer = 0.f;
    double low = 0.f, high = min(x, y);
    while (high - low > 0.000001) {
        double mid = (high + low) / 2.f;
        if (getHeight(x, y, mid) >= c) {
            answer = mid;
            low = mid;
        } else high = mid;
    }
    
    printf("%.3lf\n", answer);
    return 0;
}
