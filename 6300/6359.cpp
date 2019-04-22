// BOJ 6359 - 만취한 상법
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<bool> doorOpen(n+1);
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= n; j+=i) {
                if (!doorOpen[j]) doorOpen[j] = true;
                else doorOpen[j] = false;
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!doorOpen[i]) ans++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}

