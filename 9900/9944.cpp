// BOJ 9944 - NxM 보드 완주하기
#include <iostream>
#include <vector>
using namespace std;
const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};
vector<vector<char> > board;
int n, m;

bool ok(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

int go(int y, int x, int emptyspace_cnt) {
    int ans = -1;
    
    // 빈 공간이 없으면 더이상 이동할 수 없음
    // 이동 횟수인 0 리턴
    if (emptyspace_cnt == 0) {
        return 0;
    }
    
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        
        // 4방향중 한 방향으로 이동
        while (ok(ny, nx) && board[ny][nx] == '.') {
            board[ny][nx] = '@';
            --emptyspace_cnt;
            ny += dy[d];
            nx += dx[d];
        }
        
        // 마지막 '.' 을 만나면 while문에서 ny, nx를 이동시키기 때문에 한번 빼줘야 한다.
        ny -= dy[d];
        nx -= dx[d];
        
        // 현재 위치랑 다음 위치랑 같지 않다면.. 이동했음
        if (!(y == ny && x == nx)) {
            int temp = go(ny, nx, emptyspace_cnt);
            // -1 을 리턴하면 이동할 수 없다는 것을 의미함
            if (temp != -1) {
                if (ans == -1 || ans > temp+1) {
                    ans = temp+1;
                }
            }
        }
        
        // 원래 상태로 되돌아 오기
        while (!(y == ny && x == nx)) {
            board[ny][nx] = '.';
            ++emptyspace_cnt;
            ny -= dy[d];
            nx -= dx[d];
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc = 1;
    while (cin >> n >> m) {
        int emptyspace_cnt = 0;
        board = vector<vector<char> >(n, vector<char>(m));
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                cin >> board[y][x];
                if (board[y][x] == '.') {
                    ++emptyspace_cnt;
                }
            }
        }
        
        int ans = -1;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (board[y][x] == '.') {
                    board[y][x] = '@';  // 방문했음을 임의의 문자로 표시
                    int temp = go(y, x, emptyspace_cnt-1);
                    if (temp != -1) {
                        if (ans == -1 || ans > temp) {
                            ans = temp;
                        }
                    }
                    board[y][x] = '.';  // 원래 상태로 초기화
                }
            }
        }
        
        cout << "Case " << tc << ": " << ans << '\n';
        ++tc;
    }

    return 0;
}
