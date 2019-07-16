// BOJ 2740 - 행렬의 곱셈
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m;
    
    vector<vector<int> > mat1(n, vector<int>(m));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> mat1[r][c];
        }
    }
    
    cin >> m >> k;
    
    vector<vector<int> > mat2(m, vector<int>(k));
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < k; c++) {
            cin >> mat2[r][c];
        }
    }
    
    vector<vector<int> > answer(n, vector<int>(k, 0));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < k; c++) {
            for (int i = 0; i < m; i++) {
                answer[r][c] += mat1[r][i] * mat2[i][c];
            }
        }
    }
    
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[0].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}
