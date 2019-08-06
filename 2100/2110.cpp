// BOJ 2110 - 공유기 설치
// 이분 탐색 응용
// -> 파라메트릭 탐색(parametric search)
// 파라메트릭 탐색(parametric search)이란?
// -> 이분 탐색을 통해 최적의 해를 찾는 방법
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, c;
    cin >> n >> c;
    
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    
    sort(pos.begin(), pos.end());
    
    int answer = 0;
    int low = 1, high = pos[n-1] - pos[0];
    while (low <= high) {
        int mid = (low + high) / 2; // mid : 거리
        int std = pos[0],  cnt = 1; // std : 기준점(첫 번째 집의 위치), cnt : 공유기 설치 수
        // 좌표상 맨 앞에 있는 집에 설치를 하고난 후, (현재 위치 - 기준점 위치) 거리를 비교하며 공유기를 설치한다.
        for (int i = 1; i < n; i++) {
            if (pos[i] - std >= mid) {
                std = pos[i];
                cnt++;
            }
        }
        
        // 공유기를 설치 했을때, 설치한 수가 설치해야되는 수보다 같거나 크면 거리를 기록한다. (answer = mid)
        // 지금 거리보다 최대 거리가 존재할 수 있으므로 low > high 가 될 때까지 탐색하며 최대 거리를 찾는다.
        if (cnt >= c) {
            answer = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    
    cout << answer << '\n';
    return 0;
}
