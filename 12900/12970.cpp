// BOJ 12970 AB
#include <iostream>
#include <vector>
using namespace std;

// 백준 온라인 강의..
// A가 a개 B가 b개 있으면
// 0 <= i < j < n 조건에서
// (i, j) 쌍이 0 ~ a*b 가 되는 문자열을 항상 만들수 있다.
// (앞 A, 뒤 B)
// 쌍 0개를 만들수 있는 경우 --> BBB...BBAAA...AA
// 문자열을 놓을수 있는 방법
// 먼저 B를 b개 놓고, A를 어디에 추가하면 좋을지 선택한다.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    // a+b = n
    // 문자열 만들기..
    for (int a = 0; a <= n; a++) {
        int b = n-a;
        // 최대 a*b 가 되는 문자열을 만들수 있는데
        // 주어진 k 쌍보다 작으면 0 <= i < j < n 조건에 적합하지 않고
        // 정답에 해당되는 문자열을 만들수 없다.
        if (a*b < k) continue;
        // 위의 조건을 통과하면 항상 만들수 있다.
        // 먼저 B를 b개 놓고 A를 어디에 추가해야 할지..
        vector<int> cnt(b+1);
        // A 놓을 위치를 cnt 배열에 담는다.
        for (int i = 0; i < a; i++) {
            int x = min(b, k);
            cnt[x] += 1;
            k -= x;
        }
        // 문자열을 만들고 종료
        for (int i = b; i >= 0; i--) {
            for (int j = 0; j < cnt[i]; j++) {
                cout << 'A';
            }
            if (i > 0) {
                cout << 'B';
            }
        }
        cout << '\n';
        return 0;
    }
    
    // 문자열을 만들수 없는 조건에 모두 걸렸을 때
    cout << -1 << '\n';
    return 0;
}
