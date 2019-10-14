// BOJ 10448 - 유레카 이론
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> t;
    int n = 1;
    while (n * (n + 1) / 2 < 1000) {
        t.push_back(n * (n + 1) / 2);
        n++;
    }
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        int target;
        cin >> target;
        
        bool find = false;
        int tSize = (int)t.size();
        for (int i = 0; i < tSize; i++) {
            for (int j = 0; j < tSize; j++) {
                for (int k = 0; k < tSize; k++) {
                    if (t[i] + t[j] + t[k] == target) {
                        find = true;
                        break;
                    }
                }
            }
        }
        
        cout << find << '\n';
    }
    
    return 0;
}
