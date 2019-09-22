#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string a, b;
    cin >> a >> b;
    
    int colSize = (int)a.length();
    int rowSize = (int)b.length();
        
    int col = 0, row = 0;
    // a를 기준으로 b에서 존재 유무를 찾아야 함..
    // 반대로 했다가 계속 틀렸음
    for (int i = 0; i < colSize; i++) {
        bool ok = false;
        for (int j = 0; j < rowSize; j++) {
            if (a[i] == b[j]) {
                col = i;
                row = j;
                ok = true;
                break;
            }
        }
        if (ok) break;
    }

    for (int r = 0; r < rowSize; r++) {
        for (int c = 0; c < colSize; c++) {
            if (r == row && c != col) cout << a[c];
            else if (c == col) cout << b[r];
            else cout << ".";
        }
        cout << '\n';
    }
    
    return 0;
}
