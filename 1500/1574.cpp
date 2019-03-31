// BOJ 1574 - 룩 어택
// 이분 매칭
#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool> > adj;
vector<int> visited;
vector<int> aMatch;
vector<int> bMatch;

int visitCnt = 1;
int r, c, n;

bool dfs(int a) {
    if (visited[a] == visitCnt) return false;
    visited[a] = visitCnt;
    
    for (int b = 0; b < c; b++) {
        if (!adj[a][b]) continue;
        if (bMatch[b] == -1 || dfs(bMatch[b])) {
            aMatch[a] = b;
            bMatch[b] = a;
            return true;
        }
    }
    
    return false;
}

int bipartiteMatch() {
    aMatch = vector<int>(r, -1);
    bMatch = vector<int>(c, -1);
    visited = vector<int>(r);
    
    int matchSize = 0;
    
    for (int a = 0; a < r; a++) {
        matchSize += dfs(a);
        visitCnt += 1;
    }
    
    return matchSize;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> r >> c >> n;
    adj = vector<vector<bool> >(r, vector<bool>(c, true));
    while (n--) {
        int y, x;
        cin >> y >> x;
        adj[y-1][x-1] = false;
    }
    
    cout << bipartiteMatch() << '\n';
    return 0;
}
