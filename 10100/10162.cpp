// BOJ 10162 - 전자레인지
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int times[] = {300, 60, 10};
const int MAX = 10001;
bool visited[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    queue<pair<vector<int>, int> > q;
    q.push({{0, 0, 0}, 0});
    visited[0] = true;
    
    while (!q.empty()) {
        vector<int> btns = q.front().first;
        int now = q.front().second;
        q.pop();
        
        if (now == t) {
            cout << btns[0] << " " << btns[1] << " " << btns[2] << '\n';
            return 0;
        }
        
        for (int i = 0; i < 3; i++) {
            int next = now + times[i];
            if (next <= t && !visited[next]) {
                visited[next] = true; btns[i]++;
                q.push(make_pair(btns, next));
            }
        }
    }
    
    cout << -1 << '\n';
    return 0;
}
