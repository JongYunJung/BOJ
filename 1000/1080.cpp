// BOJ 1080 - 행렬
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int> > aArr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            if (input[j] == '0') aArr[i][j] = 0;
            else aArr[i][j] = 1;
        }
    }
    
    vector<vector<int> > bArr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            if (input[j] == '0') bArr[i][j] = 0;
            else bArr[i][j] = 1;
        }
    }
    
    // n 또는 m 이 3보다 작으면 결과만 비교
    if (n < 3 || m < 3) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (aArr[i][j] != bArr[i][j]) {
                    ok = false;
                    break;
                }
            }
        }
        cout << ((ok) ? 0 : -1) << '\n';
        return 0;
    }
    
    // n 그리고 m 3이상이면 찾도록 하자
    int ans = 0;
    bool change = false;
    for (int i = 0; i+3 <= n; i++) {
        for (int j = 0; j+3 <= m; j++) {
            if (aArr[i][j] != bArr[i][j]) {
                for (int k = i; k < i+3; k++) {
                    for (int l = j; l < j+3; l++) {
                        aArr[k][l] = (aArr[k][l] == 0) ? 1 : 0;
                    }
                }
                ans++;
            }
            // 같은지 비교
            bool ok = true;
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    if (aArr[k][l] != bArr[k][l]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            
            if (ok) {
                change = true;
                break;
            }
        }
        if (change) break;
    }
    
    cout << ((change) ? ans : -1) << '\n';
    return 0;
}
