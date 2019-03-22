// BOJ 1002 - 터렛
// 두 원의 교점의 개수를 구하는 문제
// 1. 원의 중심간의 거리를 알아야 한다.
// 2. 두 원의 위치 관계를 알아야 한다.
//      - 두 점에서 만나는 경우
//      - 한 점에서 만나는 경우 (내접, 외접)
//      - 만나지 않는 경우
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double d = sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0));
        
        if (x1 == x2 && y1 == y2) {
            if (r1 == r2) cout << -1 << '\n';
            else cout << 0 << '\n';
        } else {
            if (abs(r1-r2) < d && d < r1+r2) cout << 2 << '\n';
            else if (abs(r1-r2) == d || r1+r2 == d) cout << 1 << '\n';
            else cout << 0 << '\n'; // d < abs(r1-r2) || r1+r2 < d
        }
    }
    
    return 0;
}
