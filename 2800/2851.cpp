// BOJ 2851 - 슈퍼 마리오
// 문제 조건에서 생각 해봐야하는 조건들이 여러 개 있다.
// 1. 처음부터 버섯을 집는다. 그러나 모든 버섯을 집을 필요는 없고 중간에 중단할 수 있다.
// 2. 중간에 버섯을 먹는것을 중단 했다면, 그 이후의 버섯은 먹을 수 없다.
//    (첫 버섯을 먹지 않았다면, 그 이후 버섯도 먹을 수 없다.)
// 3. 받은 점수의 합을 최대한 100에 가깝게 만들어야 하지만 98 과 102 같은 경우에는 큰 수를 고른다.
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int scoreSize = 10;
    vector<int> score(scoreSize);
    for (int i = 0; i < scoreSize; i++) {
        cin >> score[i];
    }
    
    int sum = 0;
    for (int i = 0; i < scoreSize; i++) {
        int afterSum = sum + score[i];
        // ex) afterSum이 102이고, sum이 98인 경우
        if (afterSum >= 100) {
            // 102 - 100 <= 100 - 98 (2 <= 2 성립)
            // 즉, 100을 더한 후가 100에 가까운지? 100을 더하기 전에 값이 100에 가까운지? 판별
            if (afterSum - 100 <= 100 - sum) {
                // 큰 수인 102를 출력
                cout << afterSum << '\n';
            } else {
                cout << sum << '\n';
            }
            return 0;
        }
        sum = afterSum;
    }
    
    cout << sum << '\n';
    return 0;
}
