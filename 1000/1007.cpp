// BOJ 1007 백터 매칭
// AB [x1-x2, y1-y2], CD [x3-x4, y3-y4]
// AB+CD [x1+x3-(x2+x4), y1+y3-(y2+y4)]
// 벡터의 크기 => sqrt((x1+x3-(x2+x4))^2 + (y1+y3-(y2+y4))^2), 크기 중에서 최소값을 고르기
// 문제 핵심 n개의 좌표중에서 n/2개의 좌표는 +값, 나머지 n/2개의 좌표는 -값을 가짐
// ex) [+ 값] => x1, x3, y1, y3, [- 값] => x2, x4, y2, y4
//
// [ 내가 해결한 방법 ]
// 0 => + 값, 1 => - 값 이라 지정해 둔다. 그리고 임의의 배열에 0 0 1 1 을 담은 후에
// 다음 순열 알고리즘을 이용해서 벡터 크기의 최소값을 구한다.
// n = 4, 0 0 1 1
// n = 6, 0 0 0 1 1 1
// n = 8, 0 0 0 0 1 1 1 1
// n = 20 제한이다. 따라서 시간 복잡도 ====> (20! / (20-(n/2))! * (n/2)!) * n
//
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(numeric_limits<double>::max_digits10);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        
        vector<pair<int, int> > pos(n);
        vector<int> perm;
        for (int i = 0; i < n; i++) {
            cin >> pos[i].first >> pos[i].second;
            if (i < n/2) perm.push_back(0);
            else perm.push_back(1);
        }
        
        double ans = -1.0;
        do {
            int x1 = 0, x2 = 0;
            int y1 = 0, y2 = 0;
            for (int i = 0; i < n; i++) {
                if (perm[i] == 0) {
                    x1 += pos[i].first;
                    y1 += pos[i].second;
                } else {
                    x2 += pos[i].first;
                    y2 += pos[i].second;
                }
            }
            double dist = sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0));
            if (ans == -1.0 || ans > dist) ans = dist;
        } while (next_permutation(perm.begin(), perm.end()));
        
        cout << ans << '\n';
    }
    
    return 0;
}
