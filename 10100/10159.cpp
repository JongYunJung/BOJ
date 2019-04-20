// BOJ 10159 - 저울
// 플로이드 와샬
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<bool> > adj(n+1, vector<bool>(n+1));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = true;
    }
    
    for (int by = 1; by <= n; by++) {
        for (int from = 1; from <= n; from++) {
            if (by == from) continue;
            if (!adj[from][by]) continue;
            for (int to = 1; to <= n; to++) {
                if (by == to) continue;
                if (adj[from][by] && adj[by][to]) {
                    adj[from][to] = true;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int ans = -1;
        for (int j = 1; j <= n; j++) {
            if (!adj[i][j] && !adj[j][i]) ans++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}

