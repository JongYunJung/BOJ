// BOJ 1495 - 기타리스트
#include <iostream>
using namespace std;
bool d[101][1001];
int v[101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, s, m;
    cin >> n >> s >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    d[0][s] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (!d[i][j]) {
                continue;
            }
            
            if (j-v[i+1] >= 0) {
                d[i+1][j-v[i+1]] = true;
            }
            if (j+v[i+1] <= m) {
                d[i+1][j+v[i+1]] = true;
            }
        }
    }
    
    int ans = -1;
    for (int i = 0; i <= m; i++) {
        if (d[n][i]) {
            ans = i;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
