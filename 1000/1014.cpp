// BOJ 1014 - 컨닝
// 이분 매칭, 최대 독립 집합, 최소 버텍스 커버
// 최대 독립 집합 - 정점들을 가능한 많이 선택하되 선택된 정점끼리는 인접하지 않게 되는 집합
// 최대 독립 집합의 크기 = 정점의 수 - 최대 매칭의 크기(최소 버텍스 커버의 크기)
// 최소 버텍스 커버 - 정점을 최소한으로 선택하여 버텍스 커버에 포함된 정점들과
//                그 정점에 연결된 간선들을 제거 하였을 때 간선이 하나도 남지 않게 되는 집합
// 최소 버텍스 커버의 크기 = 최대 매칭의 크기
// 최대 독립 집합의 여집합 = 최소 버텍스 커버
// 최대 독립 집합 = 최소 버텍스 커버의 여집합
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int dy[] = {-1, -1, 0, 0, 1, 1};
const int dx[] = {-1, 1, -1, 1, -1, 1};

vector<vector<int> > numbers;
vector<int> adj[101];
vector<int> visited;
vector<int> aMatch;
vector<int> bMatch;
vector<int> points;

int visitCnt = 1;
int n, m;

bool dfs(int a) {
    if (visited[a] == visitCnt) return false;
    visited[a] = visitCnt;
    
    for (int b : adj[a]) {
        if (bMatch[b] == - 1 || dfs(bMatch[b])) {
            aMatch[a] = b;
            bMatch[b] = a;
            return true;
        }
    }
    
    return false;
}

int bipartiteMatch() {
    visited = vector<int>(n*m+1);
    aMatch = vector<int>(n*m+1, -1);
    bMatch = vector<int>(n*m+1, -1);
    
    int size = 0;
    for (int a : points) {
        size += dfs(a);
        visitCnt += 1;
    }
    
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        
        string room[n];
        for (int i = 0; i < n; i++) {
            cin >> room[i];
        }
        
        int crash = 0;
        int number = 0;
        points.clear();
        numbers = vector<vector<int> >(n, vector<int>(m));
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (room[y][x] == 'x') crash += 1;
                if (x % 2 == 0) points.push_back(number);
                numbers[y][x] = number++;
            }
        }
        
        for (int i = 0; i < n*m; i++) adj[i].clear();
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x+=2) {
                if (room[y][x] == 'x') continue;
                for (int d = 0; d < 6; d++) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                    if (room[ny][nx] == 'x') continue;
                    adj[numbers[y][x]].push_back(numbers[ny][nx]);
                }
            }
        }
        
        int size = bipartiteMatch();
        cout << (n * m) - size - crash << '\n';
    }
    
    return 0;
}

