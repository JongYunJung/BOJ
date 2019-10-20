// BOJ 4179 - 불!
// DFS 알고리즘으로 풀려고 했으나 계속 틀림
// BFS 알고리즘으로 구현하자
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

vector<pair<int, int> > fires;
vector<vector<char> > map;

int r, c;

int bfs(int y, int x) {
    queue<pair<int, int> > flame;
    for (auto fire : fires) {
        flame.push(fire);
    }
    
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    
    int answer = 0;
    while (!q.empty()) {
        int flameSize = (int)flame.size();
        for (int i = 0; i < flameSize; i++) {
            int fy = flame.front().first;
            int fx = flame.front().second;
            flame.pop();
            
            for (int d = 0; d < 4; d++) {
                int ny = fy + dy[d];
                int nx = fx + dx[d];
                
                if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
                    continue;
                }
                
                if (map[ny][nx] == '#' || map[ny][nx] == 'F') {
                    continue;
                }
        
                map[ny][nx] = 'F';
                
                flame.push(make_pair(ny, nx));
            }
        }
        
        int jihoonSize = (int)q.size();
        for (int i = 0; i < jihoonSize; i++) {
            int jy = q.front().first;
            int jx = q.front().second;
            q.pop();
            
            if (jy == 0 || jy == r-1 || jx == 0 || jx == c-1) {
                return answer + 1;
            }
            
            for (int d = 0; d < 4; d++) {
                int ny = jy + dy[d];
                int nx = jx + dx[d];
                
                if (map[ny][nx] == '#' || map[ny][nx] == 'F') {
                    continue;
                }
                
                if (map[ny][nx] == '.') {
                    map[ny][nx] = 'J';
                    q.push(make_pair(ny, nx));
                }
            }
        }
        
        answer++;
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> r >> c;
    
    map = vector<vector<char> >(r, vector<char>(c));
    
    int jy = 0, jx = 0;
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            cin >> map[y][x];
            if (map[y][x] == 'J') {
                jy = y;
                jx = x;
            } else if (map[y][x] == 'F') {
                fires.push_back(make_pair(y, x));
            }
        }
    }
    
    int answer = bfs(jy, jx);
    if (answer == -1) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << answer << '\n';
    }
    
    return 0;
}
