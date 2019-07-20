// BOJ 4307 - 개미
// 현재 개미의 위치가 주어지면,
// 1. 현재 위치에서 왼쪽 막대 끝 까지의 거리 = 이동 시간
// 2. 현재 위치에서 오른쪽 맏개 끝 까지의 거리 = 이동 시간
// 두 개의 값 중에서 큰 값은 문제에서 요구하는 "느린 시간" 이고, 작은 값은 "빠른 시간" 이다.
// 다만 여러 마리의 개미가 존재하기 때문에 그 중에서도 가장 오래 걸리는 시간을 구해야 한다.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int l, n;
        cin >> l >> n;
        
        // 해결 코드 1 - 수행 속도 36 ms, 메모리 3528 KB
        // 첫 번째로 생각해서 구현한 코드
        vector<int> tempSlow, tempFast;
        for (int i = 0; i < n; i++) {
            int pos;
            cin >> pos;
            
            int cureentToLeft  = pos;
            int currentToRight = l - pos;
            if (currentToRight >= cureentToLeft) {
                tempSlow.push_back(currentToRight);
                tempFast.push_back(cureentToLeft);
            } else {
                tempSlow.push_back(cureentToLeft);
                tempFast.push_back(currentToRight);
            }
        }
        
        int fast = *max_element(tempFast.begin(), tempFast.end());
        int slow = *max_element(tempSlow.begin(), tempSlow.end());
        
        cout << fast << " " << slow << '\n';
        
        // 해결 코드 2 - 수행 속도 32 ms, 메모리 1988 KB
        // 블로그를 참고하여 최적화한 코드
        int minSec = 0, maxSec = 0;
        for (int i = 0; i < n; i++) {
            int antPos;
            cin >> antPos;
            
            int antMin = min(antPos, l - antPos);
            int antMax = max(antPos, l - antPos);
            
            minSec = max(minSec, antMin);
            maxSec = max(maxSec, antMax);
        }
        
        cout << minSec << " " << maxSec << '\n';
    }
    
    return 0;
}
