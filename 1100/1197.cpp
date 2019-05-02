// BOJ 1197 - 최소 스패닝 트리
#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX_V = 10001;
vector<pair<int, int> > adj[MAX_V];

int prim(int n) {
    vector<bool> added(n+1, false);
    vector<int> minWeight(n+1, INF);
    
    int cost = 0;
    minWeight[1] = 0;
    for (int iter = 0; iter < n; iter++) {
        int u = 0;
        for (int v = 1; v <= n; v++) {
            if (!added[v] && (u == 0 || minWeight[u] > minWeight[v])) {
                u = v;
            }
        }
        
        added[u] = true;
        cost += minWeight[u];
        
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (!added[v] && minWeight[v] > w) {
                minWeight[v] = w;
            }
        }
    }
    
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
    cout << prim(n) << '\n';
    return 0;
}
