// BOJ 1260 - DFS 와 BFS
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> adj[1001];
bool visited[1001];

void dfs(int here) {
    visited[here] = true;
    
    printf("%d ", here);
    
    for (size_t i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];
        
        if (!visited[there]) {
            dfs(there);
        }
    }
}

void bfs(int start) {
    memset(visited, false, sizeof(visited));
    
    queue<int> q;
    q.push(start);
    
    visited[start] = true;
    
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        
        printf("%d ", here);
        
        for (size_t i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i];
            
            if (!visited[there]) {
                visited[there] = true;
                q.push(there);
            }
        }
    }
}

int main() {
    int n, m, startNode;
    scanf("%d %d %d", &n, &m, &startNode);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    dfs(startNode);
    printf("\n");
    
    bfs(startNode);
    printf("\n");
    
    return 0;
}
