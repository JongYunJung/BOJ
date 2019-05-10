// BOJ 1100 - 하얀 칸
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int ans = 0;
    string board[8];
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
        for (int j = 0; j < 8; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0 && board[i][j] == 'F') {
                    ans++;
                }
            } else {
                if (j % 2 == 1 && board[i][j] == 'F') {
                    ans++;
                }
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}

