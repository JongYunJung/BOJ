// BOJ 9325 - 얼마?
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        int s;
        cin >> s;
        
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int q, p;
            cin >> q >> p;
            s += (q * p);
        }
        
        cout << s << '\n';
    }
    
    return 0;
}
