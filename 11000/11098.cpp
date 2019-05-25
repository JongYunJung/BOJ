// BOJ 11098 - 첼시를 도와줘!
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    while (n--) {
        int p;
        cin >> p;
        vector<pair<int, string> > info(p);
        for (int i = 0; i < p; i++) {
            cin >> info[i].first >> info[i].second;
        }
        
        sort(info.begin(), info.end());
        cout << info[p-1].second << '\n';
    }
    
    return 0;
}
