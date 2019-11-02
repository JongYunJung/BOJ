// BOJ 1726 - 로봇
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int dY[] = {0, 0, 0, 1, -1};
const int dX[] = {0, 1, -1, 0, 0};
const int MAX = 100;

tuple<int, int, int> startInfo;
tuple<int, int, int> endInfo;

bool visited[MAX][MAX][5];

int map[MAX][MAX];
int n, m;

int bfs() {
    int sY, sX, sDir;
    tie(sY, sX, sDir) = startInfo;
    
    int eY, eX, eDir;
    tie(eY, eX, eDir) = endInfo;
    
    queue<tuple<int, int, int, int> > q;
    q.push(make_tuple(sY, sX, sDir, 0));
    visited[sY][sX][sDir] = true;
    
    int answer = -1;
    while (!q.empty()) {
        int cY, cX, cDir, cnt;
        tie(cY, cX, cDir, cnt) = q.front();
        q.pop();

        if (cY == eY && cX == eX && cDir == eDir) {
            answer = cnt;
            break;
        }
        
        for (int k = 1; k <= 3; k++) {
            int nY = cY + dY[cDir] * k;
            int nX = cX + dX[cDir] * k;
            
            if (nY < 0 || nY >= n || nX < 0 || nX >= m || map[nY][nX]) break;
            
            if (visited[nY][nX][cDir]) continue;
            
            visited[nY][nX][cDir] = true;
            q.push(make_tuple(nY, nX, cDir, cnt+1));
        }
        
        for (int d = 1; d <= 4; d++) {
            if (d == cDir || visited[cY][cX][d]) continue;
            
            visited[cY][cX][d] = true;
            // 로봇은 왼쪽으로 돌던지 오른쪽으로 돌던지 최소로 회전하는 각도는 180도까지이다.
            // 180도 회전하는 경우
            if ((d == 1 && cDir == 2) || (d == 2 && cDir == 1) ||
                (d == 3 && cDir == 4) || (d == 4 && cDir == 3)) {
                q.push(make_tuple(cY, cX, d, cnt+2));
            } else {
                // 90도 회전하는 경우
                q.push(make_tuple(cY, cX, d, cnt+1));
            }
        }
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }
    
    int sY, sX, sDir;
    cin >> sY >> sX >> sDir;
    startInfo = make_tuple(sY-1, sX-1, sDir);
    
    int eY, eX, eDir;
    cin >> eY >> eX >> eDir;
    endInfo = make_tuple(eY-1, eX-1, eDir);
    
    cout << bfs() << '\n';
    
    return 0;
}
