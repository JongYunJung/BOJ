// BOJ 9525 - 룩 배치하기
// 이분 매칭
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> adj[50*100];
vector<int> visited;
vector<int> aMatch;
vector<int> bMatch;
int visitCnt = 1;

bool dfs(int a) {
    if (visited[a] == visitCnt) return false;
    visited[a] = visitCnt;
    
    for (int i = 0; i < adj[a].size(); i++) {
        int b = adj[a][i];
        if (bMatch[b] == -1 || dfs(bMatch[b])) {
            aMatch[a] = b;
            bMatch[b] = a;
            return true;
        }
    }
    
    return false;
}

int bipartiteMatch(int aVertexCount, int bVertexCount) {
    visited = vector<int>(aVertexCount);
    aMatch = vector<int>(aVertexCount, -1);
    bMatch = vector<int>(bVertexCount, -1);
    
    int matchSize = 0;
    
    for (int a = 0; a < aVertexCount; a++) {
        matchSize += dfs(a);
        visitCnt += 1;
    }
    
    return matchSize;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    string board[n];
    for (int r = 0; r < n; r++) {
        cin >> board[r];
    }
    
    vector<vector<int> > rowNumbering(n, vector<int>(n, -1));
    int rowNumber = 0;
    for (int r = 0; r < n; r++) {
        bool chk = false;
        for (int c = 0; c < n; c++) {
            if (board[r][c] == '.') {
                rowNumbering[r][c] = rowNumber;
                chk = true;
            } else {
                if (chk) {
                    rowNumber += 1;
                    chk = false;
                }
            }
        }
        if (chk) rowNumber += 1;
    }
    
    vector<vector<int> > colNumbering(n, vector<int>(n, -1));
    int colNumber = 0;
    for (int c = 0; c < n; c++) {
        bool chk = false;
        for (int r = 0; r < n; r++) {
            if (board[r][c] == '.') {
                colNumbering[r][c] = colNumber;
                chk = true;
            } else {
                if (chk) {
                    colNumber += 1;
                    chk = false;
                }
            }
        }
        if (chk) colNumber += 1;
    }
    
    for (int r = 0;  r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (board[r][c] == 'x') continue;
            adj[rowNumbering[r][c]].push_back(colNumbering[r][c]);
        }
    }
    
    cout << bipartiteMatch(rowNumber, colNumber) << '\n';
    return 0;
}

