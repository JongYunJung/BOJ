// BOJ 7576 - 토마토
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int bfs(vector<vector<int> >& map, vector<pair<int, int> >& initPos) {
    queue<pair<int, int> > q;
    for (auto pos : initPos) {
        q.push(make_pair(pos.first, pos.second));
    }
    
    int n = (int)map.size();
    int m = (int)map[0].size();
    
    int date = 0;
    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        
        for (int d = 0; d < 4; d++) {
            int nextY = curY + dy[d];
            int nextX = curX + dx[d];
            
            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
                continue;
            
            if (map[nextY][nextX] == 0) {
                map[nextY][nextX] = map[curY][curX] + 1;
                date = max(date, map[curY][curX]);
                q.push(make_pair(nextY, nextX));
            }
        }
    }
    
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (map[y][x] == 0) {
                date = -1;
                break;
            }
        }
    }
    
    return date;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    
    vector<vector<int> > map(n, vector<int>(m));
    vector<pair<int, int> > initPos;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
            if (map[y][x] == 1) {
                initPos.push_back(make_pair(y, x));
            }
        }
    }
    
    cout << bfs(map, initPos) << '\n';
    return 0;
}
