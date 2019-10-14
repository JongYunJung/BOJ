// BOJ 11559 - Puyo Puyo
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

const int ROW = 12;
const int COL = 6;

vector<pair<int, int> > puyos;
vector<vector<bool> > visited;

string map[ROW];

void dfs(int y, int x, char target) {
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || ny >= ROW || nx < 0 || nx >= COL) continue;
        if (map[ny][nx] == '.') continue;
        if (!visited[ny][nx] && map[ny][nx] == target) {
            puyos.push_back(make_pair(ny, nx));
            visited[ny][nx] = true;
            dfs(ny, nx, target);
        }
    }
}

void updateMap() {
    for (int x = 0; x < COL; x++) {
        vector<char> puyo;
        for (int y = ROW-1; y >= 0; y--) {
            if (map[y][x] != '.') {
                puyo.push_back(map[y][x]);
                map[y][x] = '.';
            }
        }
        for (int i = 0; i < puyo.size(); i++) {
            map[ROW-i-1][x] = puyo[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for (int y = 0; y < ROW; y++) {
        cin >> map[y];
    }
    
    int answer = 0;
    while (true) {
        visited = vector<vector<bool> >(ROW, vector<bool>(COL));
        
        bool flag = false;
        for (int y = 0; y < ROW; y++) {
            for (int x = 0; x < COL; x++) {
                if (map[y][x] == '.') continue;
                if (visited[y][x]) continue;
                puyos.clear();
                dfs(y, x, map[y][x]);
                if (puyos.size() >= 4) {
                    for (auto p : puyos) {
                        map[p.first][p.second] = '.';
                    }
                    flag = true;
                }
            }
        }
        
        if (!flag) break;
        
        updateMap();
        
        answer++;
    }
    
    cout << answer << '\n';
    
    return 0;
}
