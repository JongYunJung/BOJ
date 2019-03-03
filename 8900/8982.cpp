// BOJ 8982 - 수족관 1
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    n -= 2; // 시작점, 끝점 제외
    n /= 2; // (x1, y1) (x2, y2) n/2 만큼의 두 좌표를 입력하면됨
    
    unordered_map<int, int> dict;   // 선분 번호도 저장을 해서 처리하는걸 쉽게 만드려고
    vector<bool> hole(n, false);
    vector<int>  bottom(n, -1);
    vector<int>  width(n, 0);
    vector<int>  top(n, 0);
    
    int x, y;
    cin >> x >> y;  // 시작점 입력
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        bottom[i] = y1;
        width[i] = x2-x1;
        dict[x2] = i;
    }
    cin >> x >> y;  // 끝점 입력
    
    int k;
    cin >> k;
    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int index = dict[x2];
        hole[index] = true;
    }
    
    // 모든 경우를 해본다.
    for (int i = 0; i < n; i++) {
        if (!hole[i]) continue;
        // 구멍 기준으로 왼쪽
        int surface = bottom[i];
        for (int j = i; j >= 0; j--) {
            surface = min(surface, bottom[j]);
            top[j] = max(top[j], surface);
        }
        // 구멍 기준으로 오른쪽
        surface = bottom[i];
        for (int j = i+1; j < n; j++) {
            surface = min(surface, bottom[j]);
            top[j] = max(top[j], surface);
        }
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (bottom[i] > top[i]) {
            ans += (long long)(bottom[i] - top[i]) * width[i];
        }
    }
    
    cout << ans << '\n';
    return 0;
}
