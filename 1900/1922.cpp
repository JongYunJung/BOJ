// BOJ 1922 - 네트워크 연결
#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX_V = 1001;

vector<pair<int, int> > adj[MAX_V];

int prim(int n) {
    vector<bool> added(n+1, false);
    vector<int> minWeight(n+1, INF);
    
    minWeight[1] = 0;
    int cost = 0;
    for (int iter = 0; iter < n; iter++) {
        int u = 0;
        for (int v = 1; v <= n; v++) {
            if (!added[v] && (u == 0 || minWeight[u] > minWeight[v])) {
                u = v;
            }
        }
        
        cost += minWeight[u];
        added[u] = true;
        
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
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
    cout << prim(n) << '\n';
    return 0;
}

