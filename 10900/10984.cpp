// BOJ 10984 - 내 학점을 구해줘
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(1);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        
        int cSum = 0;
        double gSum = 0.f;
        for (int i = 0; i < n; i++) {
            int c;
            double g;
            cin >> c >> g;
            cSum += c;
            gSum += g * c;
        }
        
        cout << cSum << " " << gSum / cSum << '\n';
    }
    
    return 0;
}
