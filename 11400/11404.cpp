// BOJ 11404 - 플로이드
// 다익스트라 알고리즘으로 N번 수행하려고 했으나
// 플로이드 와샬 알고리즘으로 구현함
// 정점과 정점사이의 간선의 가중치가 1 이면 BFS 알고리즘으로 풀지만,
// 정점과 정점사이의 간선의 가중치가 2 이상 이면 다익스트라 알고리즘 또는 플로이드 와샬 알고리즘으로 푼다.
// 다익스트라 알고리즘 -> O(ElogV)의 시간 복잡도
// 한 정점에서 모든 정점의 최단거리를 구하는 문제 (가중치가 2 이상, 음수 가중치에 대한 처리가 어려움)
// priority_queue 을 이용해서 풀기
// 플로이드 와샬 알고리즘 O(V^3)의 시간복잡도
// 모든 정점 사이의 최단거리를 구하는 문제 (가중치 2 이상, 사이클이 없는 경우 음수 가중치 처리가 가능하다.)
// for loop 를 이용하여 풀기 (from -> by, by -> to)
// by -> 경유할 정점, from -> 시작할 정점, to -> 도착하는 정점
#include <iostream>
#include <vector>
using namespace std;
const int INF = 987654321;

void floyd_warshall(vector<vector<int> >& adj, int n) {
    for (int by = 1; by <= n; by++) {
        for (int from = 1; from <= n; from++) {
            if (by == from) continue;
            for (int to = 1; to <= n; to++) {
                if (by == to) continue;
                if (adj[from][by] != INF && adj[by][to] != INF) {
                    adj[from][to] = min(adj[from][to], adj[from][by] + adj[by][to]);
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || adj[i][j] == INF) cout << 0 << " ";
            else cout << adj[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n+1, vector<int>(n+1, INF));
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        if (adj[u][v] > c) {
            adj[u][v] = c;
        }
    }
    
    floyd_warshall(adj, n);
    return 0;
}

