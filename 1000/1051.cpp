// BOJ 1051 - 숫자 정사각형
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    string rect[n];
    for (int i = 0; i < n; i++) {
        cin >> rect[i];
    }
    
    int max_size = 1;
    int limit = min(n, m);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            int standardNum = rect[y][x];
            for (int k = 1; k < limit; k++) {
                if (y + k >= n || x + k >= m) continue;
                if (standardNum != rect[y][x+k]) continue;
                if (standardNum != rect[y+k][x]) continue;
                if (standardNum != rect[y+k][x+k]) continue;
                max_size = max(max_size, k+1);
            }
        }
    }
    
    cout << max_size * max_size << '\n';
    return 0;
}
