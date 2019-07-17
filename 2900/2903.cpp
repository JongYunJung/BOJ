// BOJ 2903 - 중앙 이동 알고리즘
#include <iostream>
#include <cmath>

using namespace std;

int cache[16];
int temp[16];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    // 내가 해결한 방식..
    // 복잡하게 생각 했다..
    // 일정한 패턴을 생각해서 코드를 작성했다.
    // 규칙을 찾아보니, 공차가 2^n 인 수열을 temp 배열에 저장해서 값을 구하는데 활용하도록 했다.
    // 첫 번째 -> 초기 값 + 5 + 4 * (0 + 0) + 3 * (0 * 0)
    // 두 번째 -> 첫 번째 값 + 5 + 4 * (1 + 1) + 3 * (1 * 1)
    // 세 번째 -> 두 번째 값 + 5 + 4 * (3 + 3) + 3 * (3 * 3)
    // 네 번째 -> 세 번째 값 + 5 + 4 * (7 + 7) + 3 * (7 + 7)
    // 즉, 괄호 사이에 있는 1, 3, 7 ... 값이 공차 2^n 으로 이루어진 수열로 생각했다.
    cache[0] = 4;
    temp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        if (i > 1) temp[i] = temp[i-1] + (int)pow(2, i-2);
        cache[i] = cache[i-1] + 5 + 4 * (temp[i] + temp[i]) + 3 * (temp[i] * temp[i]);
    }
    
    cout << cache[n] << '\n';
    
    // 다른 사람 풀이..
    // 첫 번째 사각형 가로점 2개 => 4
    // 두 번째 사각형 가로점 3개 => 9
    // 세 번째 사각형 가로점 5개 => 25
    // 현재의 가로점이 cnt라면, 다음 가로점은 2 * cnt - 1 이다.
    int cnt = 2;
    for (int i = 0; i < n; i++) {
        cnt += cnt - 1;
    }
    
    cout << cnt * cnt << '\n';
    return 0;
}
