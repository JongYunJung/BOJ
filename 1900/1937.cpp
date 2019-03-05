// BOJ 1937 - 욕심쟁이 판다
#include <iostream>
using namespace std;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int map[500][500];
int dp[500][500];
int n;

int go(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= n) {
        return 0;
    }
    
    if (dp[i][j] != 0) {
        return dp[i][j];
    }
    
    dp[i][j] = 1;
    for (int d = 0; d < 4; d++) {
        int y = i + dy[d];
        int x = j + dx[d];
        if (map[i][j] < map[y][x]) {
            dp[i][j] = max(dp[i][j], go(y, x)+1);
        }
    }
    
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, go(i, j));
        }
    }
    
    cout << ans << '\n';
    return 0;
}

