// BOJ 1780 - 종이의 개수
// 분할 정복
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > matrix;
vector<int> answer;

bool isSame(int y, int x, int n) {
    for (int i = y; i < y+n; i++) {
        for (int j = x; j < x+n; j++) {
            if (matrix[y][x] != matrix[i][j]) return false;
        }
    }
    return true;
}

void go(int y, int x, int n) {
    if (isSame(y, x, n)) {
        answer[matrix[y][x]+1]++;
        return;
    }
    
    int div = n / 3;
    go(y, x, div);
    go(y, x+div, div);
    go(y, x+2*div, div);
    
    go(y+div, x, div);
    go(y+div, x+div, div);
    go(y+div, x+2*div, div);
    
    go(y+2*div, x, div);
    go(y+2*div, x+div, div);
    go(y+2*div, x+2*div, div);
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    matrix = vector<vector<int> >(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    answer = vector<int>(3);
    go(0, 0, n);
    for (int ans : answer) cout << ans << " ";
    cout << '\n';
    
    return 0;
}
