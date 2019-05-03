// BOJ 9466 - 텀 프로젝트
// 사이클을 찾는 문제인것은 파악을 했지만
// 구현을 하지 못해서 블로그를 참고했다.
// 구현 방법은 다음과 같다.
// 1 -> 2 -> 3 -> 4 인 그래프 관계에서
// 2 -> 3 -> 4 가 사이클을 이룬다면
// 현재 위치에서 방문 배열에 depth를 기록한다.
// 1 (depth : 1) -> 2 (depth : 2) -> 3 (depth : 3) -> 4 (depth : 4) 에서
// 4 -> 2 로 가는 경우에는 depth는 5가 되고 visited[2] 인 위치에서 depth는 2이다.
// 따라서 depth - visited[2] 를 해주면 사이클을 이루는 정점의 갯수를 알 수 있다. (5 - 2 = 3)
#include <iostream>
#include <vector>
using namespace std;
vector<int> visited;
vector<int> first;
vector<int> adj;

int dfs(int start, int now, int depth) {
    if (visited[now]) {
        if (first[now] != start) return 0;
        return depth - visited[now];
    }
    
    first[now] = start;
    visited[now] = depth;
    return dfs(start, adj[now], depth+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        visited = vector<int>(n+1);
        first = vector<int>(n+1);
        adj = vector<int>(n+1);
        for (int u = 1; u <= n; u++) {
            cin >> adj[u];
        }
        
        int ans = 0;
        for (int now = 1; now <= n; now++) {
            if (!visited[now]) {
                ans += dfs(now, now, 1);
            }
        }
        
        cout << n - ans << '\n';
    }
    
    return 0;
}

