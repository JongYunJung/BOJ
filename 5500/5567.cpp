#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > adj;
vector<bool> check;

void find(int now) {
    for (int i = 0; i < adj[now].size(); i++) {
        int next = adj[now][i];
        if (!check[next]) {
            check[next] = true;
        }
    }
    
    // 친구의 친구 구하기
    if (now == 1) {
        for (int i = 0; i < adj[now].size(); i++) {
            int next = adj[now][i];
            find(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    adj = vector<vector<int> >(n+1);
    check = vector<bool>(n+1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    find(1);
    
    int answer = 0;
    for (int i = 2; i <= n; i++) {
        if (check[i]) answer++;
    }
    
    cout << answer << '\n';
    return 0;
}
