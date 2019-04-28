// BOJ 1072 - 게임
// 이분 탐색 응용으로 해결할 수 있다.. -> 파라메트릭 서치???
// 틀려서 블로그를 참고하면서 해결함..
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long x, y;
    cin >> x >> y;
    
    // z 가 99% 이면 몇변을 이겨도 100% 될 수가 없다.
    long long z = (y * 100) / x;
    if (z >= 99) {
        cout << -1 << '\n';
        return 0;
    }
    
    // x의 크기가 1,000,000,000 이므로 이분 탐색을 이용하여 찾자
    // 핵심! 현재 승률보다 높으면 되지만, 가장 최소 게임을 통해 현재 승률보다 높아지면 된다.
    // 승률 중에서도 현재 승률에 근접한 승률을 찾으면 된다!!!
    const int MAX = 1e9;
    int left = 0, right = MAX;
    int answer = -1;
    while (left <= right) {
        // mid => 게임 수
        int mid = (left + right) / 2;
        long long zz = ((y + mid) * 100) / (x + mid);
        
        if (z >= zz) {
            // 승률을 계속해서 갱신 -> 현재 승률의 + 1 인 승률을 찾기 위해서
            // 게임 수를 줄여 나간다.
            left = mid + 1;
            answer = mid + 1;
        } else {
            // 이분 탐색을 이용해서 승률을 구했는데
            // 그 승률이 현재 승률보다 크지만
            // 최소 게임 수를 구해야 한다. (현재 승률에 근접한 승률을 찾아야 한다.)
            right = mid - 1;
        }
    }
    
    cout << answer << '\n';
    return 0;
}
