// BOJ 1520 - 내리막길
// DFS + DP
// Top - Down 방식으로..
// 1.DFS 4방향 탐색을 하면서 [n-1][m-1] 지점에 도달하는 순간 경로가 존재 하므로 1을 리턴
// 2. 계속 리턴을 하면서 이동이 가능한 내리막길이 존재하면 그 방향으로 DFS 시작
// 3. 중간에 왔던 길을 만나면 해당 경로 값을 리턴하면서 다시 거슬러 올라감 (가지 치기)
// 1, 2, 3 과정을 여러번 거치면서 문제를 해결해야 한다.
#include <iostream>
#include <cstring>
using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int map[500][500];
int dp[500][500];
int n, m;

int dfs(int y, int x) {
    if (y == n-1 && x == m-1) return 1;
    if (dp[y][x] != -1) return dp[y][x];
    
    int& ans = dp[y][x] = 0;
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
            continue;
        }
        if (map[y][x] > map[ny][nx]) {
            ans += dfs(ny, nx);
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> map[r][c];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0) << '\n';
    return 0;
}

