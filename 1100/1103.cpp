// BOJ 1103 - 게임
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
const int MAX = 50;
int dp[MAX][MAX];
int n, m;

bool finished[MAX][MAX];
bool visited[MAX][MAX];
bool isCycle = false;
string board[MAX];

int dfs(int y, int x) {
    visited[y][x] = true;
    int& ans = dp[y][x] = 1;
    int weight = board[y][x] - '0';
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d] * weight;
        int nx = x + dx[d] * weight;
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (!visited[ny][nx]) ans = max(ans, dfs(ny, nx)+1);
        else {
            // 해당 이전 좌표를 방문(visited == true)해서 dfs 탐색을 하고 있는데,
            // 다음 좌표가 끝나는 경우(finished == true)는 사이클이 존재하지 않지만,
            // 다음 좌표가 아직 끝나지 않은 경우(finished == false)가 된다는 얘기는
            // 사이클이 존재한다는 얘기이므로 사이클이 있다는 표시를 해준다. (isCycle = true)
            if (finished[ny][nx]) ans = max(ans, dp[ny][nx] + 1);
            else isCycle = true;
        }
    }
    finished[y][x] = true;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'H') {
                visited[i][j] = finished[i][j] = true;
                dp[i][j] = 0;
            }
        }
    }
    
    int ans = dfs(0, 0);
    cout << ((isCycle) ? -1 : ans) << '\n';
    return 0;
}
