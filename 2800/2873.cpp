// BOJ 2873 - 롤러코스터
// dfs, 백트래킹의 문제인줄 알고 풀었으나 메모리 초과가 나왔다.
// 찾아보니 그리디 알고리즘 문제였다.
#include <iostream>
#include <string>
using namespace std;
int map[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int r, c;
    cin >> r >> c;
    
    string ans = "";
    if (r % 2 == 0 && c % 2 == 0) {
        // 최소인 위치 찾기 - 행과 열이 둘 다 짝수인 경우를 위해서
        int minVal = 1000;
        pair<int, int> minPos;
        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++) {
                cin >> map[y][x];
                if ((y + x) % 2 == 1 && minVal > map[y][x]) {
                    minVal = map[y][x];
                    minPos = {y, x};
                }
            }
        }
        
        // 최소값이 있는 행 직전까지 이동하는데 짝수이면 직전의 행까지 홀수이면, 직전의 행 - 1 까지
        int nR = (minPos.first % 2 == 0) ? minPos.first : minPos.first - 1;
        for (int y = 0; y < nR; y++) {
            for (int x = 1; x < c; x++) {
                if (y % 2 == 0) ans += 'R';
                else ans += 'L';
            }
            ans += 'D';
        }
        
        // 핵심을 구현해야함.. 최소값 위치 피하기
        // 최소값이 위치해있는 좌측 부근까지 이동
        int nC = minPos.second;
        for (int x = 0; x < nC; x++) {
            if (x % 2 == 0) ans += "DR";
            else ans += "UR";
        }
        
        // 최소값의 위치를 피해 가장 우측까지 이동
        for (int x = nC; x < c - 1; x++) {
            if (x % 2 == 0) ans += "RD";
            else ans += "RU";
        }
        
        // 목적지까지 이동 (나머지 이동)
        if (minPos.first % 2 == 0) nR = r - (minPos.first + 2);
        else nR = r - (minPos.first + 1);
        for (int y = 0; y < nR; y++) {
            ans += 'D';
            for (int x = 1; x < c; x++) {
                if (y % 2 == 0) ans += 'L';
                else ans += 'R';
            }
        }
    } else if (r % 2 == 1) {
        for (int y = 0; y < r; y++) {
            if (y != 0) ans += 'D';
            for (int x = 1; x < c; x++) {
                if (y % 2 == 0) ans += 'R';
                else ans += 'L';
            }
        }
    } else if (c % 2 == 1) {
        for (int x = 0; x < c; x++) {
            if (x != 0) ans += 'R';
            for (int y = 1; y < r; y++) {
                if (x % 2 == 0) ans += 'D';
                else ans += 'U';
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}
