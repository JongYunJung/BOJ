// BOJ 2875 - 대회 or 인턴
// 그리디 알고리즘
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    // 내가 해결한 방법
    // 1. 대회 팀을 먼저 만든다.
    int team = 0;
    while (n - 2 >= 0 && m - 1 >= 0) {
        n -= 2;
        m -= 1;
        team++;
    }
    
    // 2. 팀을 만들지 못한 남은 사람들 중에서 k명(인턴의 수)보다 크거나 같으면, 아무나 뽑으면 된다.
    // 그러나 k명보다 작게 되면 대회 팀을 해산해야 한다.
    int others = n + m;
    // 0이 아닌 양수이면, 인턴으로 뽑을사람이 부족하다.
    if (k - others > 0) {
        // (필요한 사람의 수 / 3)개의 팀을 해산해야 한다.
        team -= ((k - others - 1) / 3) + 1;
    }
    
    cout << team << '\n';
    return 0;
}
