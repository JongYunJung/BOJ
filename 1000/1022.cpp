// BOJ 1022 - 소용돌이 예쁘게 출력하기
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};

int map[50][5];

int main() {
    int r1, c1, r2, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    
    memset(map, 0, sizeof(map));
    int rr = r2-r1, cc = c2-c1;
    int y = 0, x = 0;
    int dir_cnt = 1;
    int cnt = 0;
    int dir = 0;
    int num = 1;
    while (!(map[0][0] != 0 && map[0][cc] != 0 && map[rr][0] != 0 && map[rr][cc] != 0)) {
        if (0 <= y-r1 && y-r1 <= rr && 0 <= x-c1 && x-c1 <= cc) map[y-r1][x-c1] = num;
        
        num += 1;
        cnt += 1;
        
        y += dy[dir];
        x += dx[dir];
        
        if (cnt == dir_cnt) {
            cnt = 0;
            dir = (dir + 1) % 4;
            if (dir == 0 || dir == 2) {
                dir_cnt += 1;
            }
        }
    }
    
    cnt = 0;
    while (num > 0) {
        num /= 10;
        cnt += 1;
    }
    
    for (int i = 0; i <= r2-r1; i++) {
        for (int j = 0; j <= c2-c1; j++) {
            printf("%*d ", cnt, map[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

