// BOJ 3085 - 사탕게임
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int dp[50][50];

int check(vector<string>& board) {
    int n = (int)board.size();
    int ans = 1;
    for (int i = 0; i < n; i++) {
        // 열과 같은지 비교
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (board[i][j] == board[i][j-1]) {
                cnt += 1;
            } else {
                cnt = 1;
            }
            ans = max(ans, cnt);
        }
        // 행과 같은지 비교
        cnt = 1;
        for (int j = 1; j < n; j++) {
            if (board[j][i] == board[j-1][i]) {
                cnt += 1;
            } else {
                cnt = 1;
            }
            ans = max(ans, cnt);
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 열에 있는 사탕과 바꿔보기
            if (j+1 < n) {
                swap(board[i][j], board[i][j+1]);
                ans = max(ans, check(board));
                swap(board[i][j], board[i][j+1]);
            }
            // 행에 있는 사탕과 바꿔보기
            if (i+1 < n) {
                swap(board[i][j], board[i+1][j]);
                ans = max(ans, check(board));
                swap(board[i][j], board[i+1][j]);
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}
