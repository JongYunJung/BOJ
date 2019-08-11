// BOJ 9663 - N-Queen
// 백트래킹 문제
#include <iostream>

using namespace std;

bool visited[15][15];

bool checkCol[15];
bool checkRtoL[29];
bool checkLtoR[29];

int n;

bool check(int row, int col) {
    if (checkCol[col]) return false;
    if (checkRtoL[row+col]) return false;
    if (checkLtoR[row-col+n-1]) return false;
    return true;
}

int go(int row) {
    if (row == n) return 1;
    
    int cnt = 0;
    for (int col = 0; col < n; col++) {
        if (!check(row, col)) continue;
        
        checkCol[col] = true;
        checkRtoL[row+col] = true;
        checkLtoR[row-col+n-1] = true;
        visited[row][col] = true;
        
        cnt += go(row + 1);
        
        checkCol[col] = false;
        checkRtoL[row+col] = false;
        checkLtoR[row-col+n-1] = false;
        visited[row][col] = false;
    }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    cout << go(0) << '\n';
    
    return 0;
}
