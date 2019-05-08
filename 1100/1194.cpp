// BOJ 1194 - 달이 차오른다, 가자.
// 비트 연산 & BFS 문제
// BFS 응용 문제로 key를 줘서 이동한다던지 벽을 부술수 있게 해서 한다는지
// 여러가지 방법이 있는거 같다.
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
const int BIT_SIZE = 64;
const int MAX = 50;

bool visited[BIT_SIZE][MAX][MAX];
string maze[MAX];
int n, m;

int bfs(int sy, int sx) {
    queue<tuple<int, int, int, int> > q;
    q.push(make_tuple(sy, sx, 0, 0));
    visited[0][sy][sx] = true;
    
    while (!q.empty()) {
        int y, x, key, cnt;
        tie(y, x, key, cnt) = q.front();
        q.pop();
        
        if (maze[y][x] == '1') return cnt;
        
        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (maze[ny][nx] == '#' || visited[key][ny][nx]) continue;
            
            if ('a' <= maze[ny][nx] && maze[ny][nx] <= 'z') {
                int nKey = key | 1 << (int)(maze[ny][nx] - 'a');
                if (!visited[nKey][ny][nx]) {
                    visited[key][ny][nx] = true;
                    visited[nKey][ny][nx] = true;
                    q.push(make_tuple(ny, nx, nKey, cnt+1));
                }
            } else if ('A' <= maze[ny][nx] && maze[ny][nx] <= 'Z') {
                if (key & 1 << (int)(maze[ny][nx] - 'A')) {
                    visited[key][ny][nx] = true;
                    q.push(make_tuple(ny, nx, key, cnt+1));
                }
            } else if (maze[ny][nx] == '.' || maze[ny][nx] == '0' || maze[ny][nx] == '1') {
                visited[key][ny][nx] = true;
                q.push(make_tuple(ny, nx, key, cnt+1));
            }
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    int sy = 0, sx = 0;
    for (int y = 0; y < n; y++) {
        cin >> maze[y];
        for (int x = 0; x < maze[y].length(); x++) {
            if (maze[y][x] == '0') {
                sy = y;
                sx = x;
            }
        }
    }
    
    cout << bfs(sy, sx) << '\n';
    return 0;
}
