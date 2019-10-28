// BOJ 2842 - 집배원 한상덕
// 풀지 못해서 블로그를 참고했다.
// 핵심.. 피로도를 1차원 배열에 담아서 정렬한 다음, 중복을 제거한다.
// 차례대로 tiredness[low] 와 tiredness[high] 사이에서만 탐색을 허용한다.
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

vector<vector<char> > map;
vector<vector<int> > tiredness;

int bfs(vector<int>& fatigue, int sy, int sx, int totalHouse, int n) {
    int answer = 0x7FFFFFFF;
    int low = 0, high = 0;
    
    while (low < fatigue.size()) {
        vector<vector<bool> > visited(n, vector<bool>(n));
        queue<pair<int, int> > q;
        
        int curFatigue = tiredness[sy][sx];
        if (fatigue[low] <= curFatigue && curFatigue <= fatigue[high]) {
            visited[sy][sx] = true;
            q.push(make_pair(sy, sx));
        }
        
        int house = 0;
        
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
            for (int d = 0; d < 8; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                
                if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) {
                    continue;
                }
                
                curFatigue = tiredness[ny][nx];
                
                if (fatigue[low] <= curFatigue && curFatigue <= fatigue[high]) {
                    if (map[ny][nx] == 'K') house++;
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
        }
        
        if (totalHouse == house) {
            answer = min(answer, fatigue[high] - fatigue[low]);
            low++;
        } else if (high + 1 < fatigue.size()) {
            high++;
        } else {
            break;
        }
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    map = vector<vector<char> >(n, vector<char>(n));
    
    int totalHouse = 0;
    int sy = 0, sx = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
            
            if (map[y][x] == 'P') {
                sy = y;
                sx = x;
            } else if (map[y][x] == 'K') {
                totalHouse++;
            }
        }
    }

    tiredness = vector<vector<int> >(n, vector<int>(n));
    
    vector<int> fatigue;
    
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> tiredness[y][x];
            
            fatigue.push_back(tiredness[y][x]);
        }
    }
    
    sort(fatigue.begin(), fatigue.end());
    
    fatigue.erase(unique(fatigue.begin(), fatigue.end()), fatigue.end());
    
    cout << bfs(fatigue, sy, sx, totalHouse, n) << '\n';
    
    return 0;
}
