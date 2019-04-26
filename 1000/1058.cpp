// BOJ 1058 - 친구
// 전형적인 플로이드 와샬 알고리즘 문제
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int INF = 987654321;
vector<vector<int> > adj;

void floyd(int n) {
    for (int by = 0; by < n; by++) {
        for (int from = 0; from < n; from++) {
            if (by == from) continue;
            for (int to = 0; to < n; to++) {
                if (by == to || from == to) continue;
                if (adj[from][to] > adj[from][by] + adj[by][to]) {
                    adj[from][to] = adj[from][by] + adj[by][to];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    adj = vector<vector<int> >(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = (s[j] == 'Y') ? 1 : INF;
        }
    }
    
    floyd(n);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (adj[i][j] <= 2) cnt++;
        }
        ans = max(ans, cnt);
    }
    
    cout << ans << '\n';
    return 0;
}

