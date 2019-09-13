// BOJ 2563 - 색종이
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<bool> > drawingPaper(100, vector<bool>(100));
    while (n--) {
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (drawingPaper[i + y][j + x]) continue;
                drawingPaper[i + y][j + x] = true;
            }
        }
    }
    
    int answer = 0;
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            if (drawingPaper[y][x]) answer++;
        }
    }
    
    cout << answer << '\n';
    return 0;
}
