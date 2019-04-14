// BOJ 1620 - 나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    string poketmon[n+1];
    map<string, int> poketmons;
    for (int i = 1; i <= n; i++) {
        cin >> poketmon[i];
        poketmons.insert({poketmon[i], i});
    }
    
    for (int i = 0; i < poketmons.size(); i++) {
    }
    
    while (m--) {
        string s;
        cin >> s;
        
        if ('A' <= s[0] && s[0] <= 'Z') {
            cout << poketmons[s];
        } else {
            cout << poketmon[stoi(s)];
        }
        
        cout << '\n';
    }
    
    return 0;
}

