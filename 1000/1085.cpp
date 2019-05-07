// BOJ 1085 - 직사각형에서 탈출
// 수학 문제
// 수학 문제는 감을 잡지 못하는 것 같음..
// 많이 풀어봐야할 것 같다.
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    
    int minValue = min(x, w-x);
    minValue = min(minValue, min(y, h-y));
    
    cout << minValue << '\n';
    return 0;
}
