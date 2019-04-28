// BOJ 2096 - 내려가기
// 무엇보다도 메모리가 4MB 인점.. 메모리 잘 사용해야 한다.
// cur_max[100001][3], cur_max[100001][3] 선언하면 메모리가 초과 된다.
// 이전 max 값과 이전 min 값을 기록해 두었다가 재 사용하는 방식으로 해결하면 된다.
// cur_max[3], cur_min[3]   => 현재 상태를 기록
// prev_max[3], prev_min[3] => 이전 상태를 기록
#include <iostream>
#include <algorithm>
using namespace std;
int prev_max[3], prev_min[3];
int cur_max[3], cur_min[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int num[3];
        cin >> num[0] >> num[1] >> num[2];
        
        cur_max[0] = max(prev_max[0], prev_max[1]) + num[0];
        cur_max[1] = max({prev_max[0], prev_max[1], prev_max[2]}) + num[1];
        cur_max[2] = max(prev_max[1], prev_max[2]) + num[2];
        
        cur_min[0] = min(prev_min[0], prev_min[1]) + num[0];
        cur_min[1] = min({prev_min[0], prev_min[1], prev_min[2]}) + num[1];
        cur_min[2] = min(prev_min[1], prev_min[2]) + num[2];
        
        for (int j = 0; j < 3; j++) {
            prev_max[j] = cur_max[j];
            prev_min[j] = cur_min[j];
        }
    }
    
    int max_ans = *max_element(cur_max, cur_max + 3);
    int min_ans = *min_element(cur_min, cur_min + 3);
    cout << max_ans << " " << min_ans << '\n';
    return 0;
}
