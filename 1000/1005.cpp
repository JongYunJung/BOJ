// BOJ 1005 - ACM Craft
// 위상정렬 - 어떤 노드를 방문할 때 반드시 선행 노드가 이미 모두 방문되어야 하는
//          조건을 만족하는 노드 방문 순서를 결정하는 정렬
// 단 방향 그래프 이미 지나간 선행 노드를 다시 되돌아 오지는 않는다.
// 여러개의 경로 중에서 어떤 것을 택하는 문제가 아니다.
// 들어오는 간선의 갯수를 확인해서 푸는 문제 (Indegree)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> adj[1001];
        vector<int> sec(n+1);
        for (int i = 1; i <= n; i++)
            cin >> sec[i];
        
        vector<int> inDegree(n+1, 0);
        for (int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;
            inDegree[v] += 1;
            adj[u].push_back(v);
        }
        
        int w;
        cin >> w;
        
        // 선행자가 없는 정점들 큐에 담기
        queue<int> q;
        for (int v = 1; v <= n; v++)
            if (inDegree[v] == 0) q.push(v);
        
        vector<int> ans(n+1, 0);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            if (now == w) break;
            for (int next : adj[now]) {
                ans[next] = max(ans[next], ans[now]+sec[now]);
                if (--inDegree[next] == 0) q.push(next);
            }
        }
        
        cout << ans[w] + sec[w] << '\n';
    }
    
    return 0;
}

