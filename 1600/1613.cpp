// BOJ 1613 - 역사
// 플로이드 와샬..
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<vector<int> > adj(n+1, vector<int>(n+1));
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = -1;
        adj[v][u] = 1;
    }
    
    for (int by = 1; by <= n; by++) {
        for (int from = 1; from <= n; from++) {
            if (by == from) continue;
            for (int to = 1; to <= n; to++) {
                if (by == to) continue;
                if (adj[from][to] != 0) continue;
                // from이 by보다 먼저 일어나고 by가 to보다 먼저 일어나면
                // from은 to보다 먼저 일어난 역사
                if (adj[from][by] == -1 && adj[by][to] == -1) {
                    adj[from][to] = -1;
                }
                // from이 by보다 늦게 일어나고 by가 to보다 늦게일어난 역사이면
                // from은 to보다 늦게 일어난 역사
                if (adj[from][by] == 1 && adj[by][to] == 1) {
                    adj[from][to] = 1;
                }
            }
        }
    }
    
    int s;
    cin >> s;
    while (s--) {
        int u, v;
        cin >> u >> v;
        cout << adj[u][v] << '\n';
    }
    
    return 0;
}

