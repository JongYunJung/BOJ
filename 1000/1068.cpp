// BOJ 1068 - 트리
// 주어진 트리를 인접리스트로 모델링 한다.
// DFS 또는 BFS 탐색을 통해 지워진 노드를 제외하고 탐색한다.
// 지워진 노드를 어떻게 구분할까? 탐색 직전 지워진 노드가 방문 했음을 표시하면 된다.
// 예외적인 부분으로 루트 노드가 지워질 수 도 있음을 생각하자.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;

int bfs(int root) {
    visited[root] = true;
    queue<int> q;
    q.push(root);
    
    int leaf = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        int child = 0;
        for (int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                child++;
            }
        }
        
        if (child == 0) {
            leaf++;
        }
    }
    
    return leaf;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int root = 0;
    visited = vector<bool>(n);
    adj = vector<vector<int> >(n);
    for (int u = 0; u < n; u++) {
        int v;
        cin >> v;
        
        if (v == -1) root = u;
        else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    int del;
    cin >> del;
    visited[del] = true;
    
    if (!visited[root]) cout << bfs(root);
    else cout << 0;
    cout << '\n';
    
    return 0;
}
