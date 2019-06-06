// BOJ 1018 - 체스판 다시 칠하기
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<char> > board(n, vector<char>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> board[y][x];
        }
    }
    
    string bMap[8], wMap[8];
    for (int i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            bMap[i] = "BWBWBWBW";
            wMap[i] = "WBWBWBWB";
        } else {
            bMap[i] = "WBWBWBWB";
            wMap[i] = "BWBWBWBW";
        }
    }
    
    int answer = 50 * 50 + 1;
    for (int y = 0; y+8 <= n; y++) {
        for (int x = 0; x+8 <= m; x++) {
            int bCount = 0, wCount = 0;
            for (int r = y; r < y+8; r++) {
                for (int c = x; c < x+8; c++) {
                    if (board[r][c] != bMap[r-y][c-x]) bCount++;
                    if (board[r][c] != wMap[r-y][c-x]) wCount++;
                }
            }
            answer = min(answer, min(bCount, wCount));
        }
    }
    
    cout << answer << '\n';
    return 0;
}
