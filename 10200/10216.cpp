// BOJ 10216 - Count Circle Groups
// 그래프 관련 문제임을 파악하고 BFS 알고리즘을 적용해 풀었다.
// 핵심
// 1. 두 점 사이의 거리를 구한다.
// 2. 두 점 사이의 거리가 반지름의 합보다 작거나 같으면 인접 리스트를 만든다.
// 3. BFS 알고리즘을 통해 그룹이 몇 개 있는지 구한다.
// 참고
// 상호 배타적 집합(DisjointSet)을 이용해 그룹이 몇 개 있는지 구할 수 있다.
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<int> > adj;
vector<bool> visited;

void bfs(int i) {
    
    queue<int> q;
    q.push(i);
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        for (int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        int n;
        cin >> n;
        
        vector<tuple<int, int, int> > info;
        for (int i = 0; i < n; i++) {
            int x, y, r;
            cin >> x >> y >> r;
            info.push_back(make_tuple(x, y, r));
        }
        
        adj = vector<vector<int> >(n);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int x1, y1, r1, x2, y2, r2;
                tie(x1, y1, r1) = info[i];
                tie(x2, y2, r2) = info[j];
                
                int x = x1 - x2;
                int y = y1 - y2;
                int r = r1 + r2;
                
                if (x * x + y * y <= r * r) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        
        visited = vector<bool>(n);
        
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                answer++;
                bfs(i);
            }
        }
        
        cout << answer << '\n';
    }
    
    return 0;
}
