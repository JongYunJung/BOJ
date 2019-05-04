// BOJ 1719 - 택배
// 다익스트라 문제 - 한 정점에서 모든 정점의 최단거리를 구한다.
// 플로이드 와샬 알고리즘으로도 풀 수 있을것 같다.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 987654321;
const int MAX = 200;

vector<pair<int, int> > adj[MAX+1];

vector<int> dijkstra(int start) {
    vector<int> dist(MAX+1, INF);
    vector<int> vertex(MAX+1);
    vertex[start] = dist[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int currentDist = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        
        if (dist[current] < currentDist) continue;
        for (int i = 0; i < adj[current].size(); i++) {
            int nextDist = currentDist + adj[current][i].second;
            int next = adj[current][i].first;
            if (dist[next] > nextDist) {
                dist[next] = nextDist;
                vertex[next] = current;
                pq.push(make_pair(-nextDist, next));
            }
        }
    }
    return vertex;
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
    
    vector<vector<int> > ans(MAX+1, vector<int>(MAX+1));
    for (int u = 1; u <= n; u++) {
        vector<int> temp = dijkstra(u);
        for (int v = 1; v <= n; v++) {
            if (u == v) continue;
            ans[v][u] = temp[v];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cout << "- ";
                continue;
            }
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}


