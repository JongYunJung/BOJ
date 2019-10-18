#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > adj;
vector<bool> visited;

void dfs(int now) {
    for (int i = 0; i < adj[now].size(); i++) {
        int next = adj[now][i];
        if (!visited[next]) {
            visited[next] = true;
            dfs(next);
        }
    }
}

int getDistance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        int n;
        cin >> n;
        
        vector<pair<int, int> > pos(n+2);
        for (int i = 0; i < n+2; i++) {
            cin >> pos[i].first >> pos[i].second;
        }
        
        adj = vector<vector<int> >(pos.size());
        for (int i = 0; i < pos.size(); i++) {
            for (int j = i+1; j < pos.size(); j++) {
                if (getDistance(pos[i], pos[j]) <= 50 * 20) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        visited = vector<bool>(n+2);
        visited[0] = true;
        dfs(0);
        
        if (visited[n+1]) {
            cout << "happy" << '\n';
        } else {
            cout << "sad" << '\n';
        }
    }
    
    return 0;
}
