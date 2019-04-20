// BOJ 2458 - 키순서
// 플로이드 와샬
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n+1, vector<int>(n+1));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }
    
    for (int by = 1; by <= n; by++) {
        for (int from = 1; from <= n; from++) {
            if (by == from) continue;
            for (int to = 1; to <= n; to++) {
                if (by == to) continue;
                if (adj[from][by] && adj[by][to]) {
                    adj[from][to] = 1;
                }
            }
        }
    }
    
    int ans = n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (!adj[i][j] && !adj[j][i]) {
                ans--;
                break;
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}

