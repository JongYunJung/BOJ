// BOJ 1760 N-Rook
// 이분 매칭
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[50*100];
vector<int> visited;
vector<int> aMatch;
vector<int> bMatch;

int board[100][100];
int visitCnt = 1;

bool dfs(int a) {
    if (visited[a] == visitCnt) return false;
    visited[a] = visitCnt;
    
    for (int b : adj[a]) {
        if (bMatch[b] == -1 || dfs(bMatch[b])) {
            aMatch[a] = b;
            bMatch[b] = a;
            return true;
        }
    }
    
    return false;
}

int bipartiteMatch(int aSize, int bSize) {
    visited = vector<int>(aSize);
    aMatch = vector<int>(aSize, -1);
    bMatch = vector<int>(bSize, -1);
    
    int matchSize = 0;
    
    for (int a = 0; a < aSize; a++) {
        matchSize += dfs(a);
        visitCnt += 1;
    }
    
    return matchSize;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            cin >> board[r][c];
        }
    }
    
    vector<vector<int> > rNums(m, vector<int>(n, -1));
    int rNum = 0;
    for (int r = 0; r < m; r++) {
        bool chk = false;
        for (int c = 0; c < n; c++) {
            if (board[r][c] == 1) continue;
            if (board[r][c] == 0) {
                rNums[r][c] = rNum;
                chk = true;
            } else {
                if (chk) {
                    rNum += 1;
                    chk = false;
                }
            }
        }
        if (chk) rNum += 1;
    }
    
    vector<vector<int> > cNums(m, vector<int>(n, -1));
    int cNum = 0;
    for (int c = 0; c < n; c++) {
        bool chk = false;
        for (int r = 0; r < m; r++) {
            if (board[r][c] == 1) continue;
            if (board[r][c] == 0) {
                cNums[r][c] = cNum;
                chk = true;
            } else {
                if (chk) {
                    cNum += 1;
                    chk = false;
                }
            }
        }
        if (chk) cNum += 1;
    }
    
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (board[r][c] == 0) adj[rNums[r][c]].push_back(cNums[r][c]);
        }
    }
    
    cout << bipartiteMatch(rNum, cNum) << '\n';
    return 0;
}

