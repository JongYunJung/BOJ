// BOJ 11557 - Yangjojang of The Year
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    unordered_map<string, int> um;
    while (tc--) {
        um.clear();
        
        int n;
        cin >> n;
        while (n--) {
            string s;
            int l;
            cin >> s >> l;
            um[s] = l;
        }
        
        string answer = "";
        int maxL = 0;
        for (auto info : um) {
            if (maxL < info.second) {
                maxL = info.second;
                answer = info.first;
            }
        }
        
        cout << answer << '\n';
    }
    
    return 0;
}
