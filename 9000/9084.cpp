// BOJ 9084 - 동전
// 쉽게 접근하자
// 예를 들면, a = {2, 3, 5}, m = 10일때
// a[0] = 2인 경우에서, 10까지 만들어 주는 경우의 수를 cache 한다.
// ex) 2인 경우에서는 다음과 같이 만들어 줄 수 있다.
// index | 0 1 2 3 4 5 6 7 8 9 10
// value | 1 0 1 0 1 0 1 0 1 0 1
// a[1] = 3인 경우를 보기전에 가장 중요한 핵심이 있다.
// m = 6일 때 경우의 수 확인해보면 2 + 2 + 2으로 6을 만들어주는 이전 경우의 수 1개,
// 3 + 3으로 6으로 만들어주는 현재의 경우의 수 1개가 존재한다.
// 따라서 이전 결과값을 더해줘야한다.
// 추가로 a[i] 보다 작은값은 탐색해 볼 필요가 없기 때문에
// 시작 인덱스를 a[i]로 설정 한다.
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_M = 10001;
int dp[MAX_M];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int m;
        cin >> m;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = a[i]; j <= m; j++) {
                dp[j] += dp[j - a[i]];
            }
        }
        
        cout << dp[m] << '\n';
    }
    
    return 0;
}
