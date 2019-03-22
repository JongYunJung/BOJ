// BOJ 1004 - 어린 왕자
// 원 안에 해당 좌표가 있는지를 알아야하는 수학 문제
// (CircleCenterX-startX)^2 + (CircleCenterY-startY)^2 < d^2
// (CircleCenterX-endX)^2 + (CircleCenterY-endY)^2 < d^2
// 다음 조건을 만족할 때 행성계에 진입하고 이탈이 필요함
// 1. 어린왕자의 시작위치가 특정 원 안에 있고,
//    도착지가 같은 원 안에 있으면 카운트 X, 도착지가 다른 원 안에 있으면 카운트 O
// 2. 도착지가 특정 원 안에 있고,
//    어린왕자의 시작점도 같은 원 안에 있으면 카운트 X, 시작점이 다른 원 안에에 있으면 카운트 O
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int x1, y1, x2, y2, n;
        cin >> x1 >> y1 >> x2 >> y2 >> n;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int cx, cy, r;
            cin >> cx >> cy >> r;
            double d1 = sqrt(pow(cx-x1, 2.0) + pow(cy-y1, 2.0));
            double d2 = sqrt(pow(cx-x2, 2.0) + pow(cy-y2, 2.0));
            if (d1 < r && d2 > r) cnt++;
            else if (d1 > r && d2 < r) cnt++;
        }
        cout << cnt << '\n';
    }
    
    return 0;
}

