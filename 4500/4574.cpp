// BOJ - 4574 스도미노쿠
// 어려워서 백준 온라인 강의 수강함..
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int n = 9;
const int dy[2] = {0, 1};
const int dx[2] = {1, 0};
bool domino[10][10];
bool chk_r[10][10];
bool chk_c[10][10];
bool chk_s[10][10];
int board[10][10];

int square(int y, int x) {
    return (y/3)*3 + (x/3);
}

void check(int y, int x, int num, bool what) {
    chk_r[y][num] = what;
    chk_c[x][num] = what;
    chk_s[square(y, x)][num] = what;
}

bool check_range(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

bool can(int y, int x, int num) {
    return !chk_r[y][num] && !chk_c[x][num] && !chk_s[square(y, x)][num];
}

void print_answer() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

bool game_start(int z) {
    if (z == 81) {
        print_answer();
        return true;
    }
    
    int y = z / n;
    int x = z % n;
    if (board[y][x] != 0) {
        return game_start(z+1);
    } else {
        for (int d = 0; d < 2; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (!check_range(ny, nx)) continue;
            if (board[ny][nx] != 0) continue;
            for (int num1 = 1; num1 <= 9; num1++) {
                for (int num2 = 1; num2 <= 9; num2++) {
                    if (num1 == num2) continue;
                    if (domino[num1][num2]) continue;
                    if (can(y, x, num1) && can(ny, nx, num2)) {
                        domino[num1][num2] = domino[num2][num1] = true;
                        check(y, x, num1, true);
                        check(ny, nx, num2, true);
                        board[y][x] = num1;
                        board[ny][nx] = num2;
                        
                        if (game_start(z+1))
                            return true;
                        
                        domino[num1][num2] = domino[num2][num1] = false;
                        check(y, x, num1, false);
                        check(ny, nx, num2, false);
                        board[y][x] = 0;
                        board[ny][nx] = 0;
                    }
                }
            }
        }
    }
    
    return false;
}

pair<int, int> convert(string pos) {
    return make_pair(pos[0]-'A', pos[1]-'1');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc = 1;
    while (true) {
        int m;
        cin >> m;
        if (m == 0) break;
        
        memset(domino, false, sizeof(domino));
        memset(chk_r, false, sizeof(chk_r));
        memset(chk_c, false, sizeof(chk_c));
        memset(chk_s, false, sizeof(chk_s));
        memset(board, 0, sizeof(board));
        
        for (int i = 0; i < m; i++) {
            int num1, num2;
            string str1, str2;
            cin >> num1 >> str1 >> num2 >> str2;
            domino[num1][num2] = domino[num2][num1] = true;
            pair<int, int> p1 = convert(str1);
            pair<int, int> p2 = convert(str2);
            board[p1.first][p1.second] = num1;
            board[p2.first][p2.second] = num2;
            check(p1.first, p1.second, num1, true);
            check(p2.first, p2.second, num2, true);
        }
        
        for (int num = 1; num <= 9; num++) {
            string str;
            cin >> str;
            pair<int, int> p = convert(str);
            board[p.first][p.second] = num;
            check(p.first, p.second, num, true);
        }
        
        cout << "Puzzle " << tc << '\n';
        game_start(0);
        ++tc;
    }
    
    return 0;
}
