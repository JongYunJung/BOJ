// BOJ 2617 - 구슬 찾기
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 99 + 1;

vector<pair<int, bool> > adj[MAX];
vector<bool> visited;

int n, m;

void dfs(int now, bool flag) {
    for (int i = 0; i < adj[now].size(); i++) {
        if (flag == adj[now][i].second) {
            int next = adj[now][i].first;
            if (!visited[next]) {
                visited[next] = true;
                dfs(next, flag);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(make_pair(v, false));
        adj[v].push_back(make_pair(u, true));
    }
    
    vector<int> maxCnt(n+1);
    vector<int> minCnt(n+1);
    for (int i = 1; i <= n; i++) {
        visited = vector<bool>(n+1);
        visited[i] = true;
        dfs(i, true);
        
        
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (visited[j]) maxCnt[j]++;
        }
        
        visited = vector<bool>(n+1);
        visited[i] = true;
        dfs(i, false);
        
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (visited[j]) minCnt[j]++;
        }
    }
    
    int answer = 0;
    int k = (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        if (maxCnt[i] >= k || minCnt[i] >= k) {
            answer++;
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}
