// BOJ 2010 - 플러그
// 기존에 사용하던 멀티탭의 플러그중 하나는 다음 멀티탭 연결을 위해서 사용된다는 것!
// 그것이 핵심이고 잘 인지하면 문제를 풀 수 있다.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> powerStrip(n);
    for (int i = 0; i < n; i++) {
        cin >> powerStrip[i];
    }
    
    int answer = powerStrip[0];
    for (int i = 1; i < n; i++) {
        answer -= 1;
        answer += powerStrip[i];
    }
    
    cout << answer << '\n';
    return 0;
}
