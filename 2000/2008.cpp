// BOJ - 2008 사다리 게임
// 풀지 못해서 백준 알고리즘 강의 참고함..
#include <iostream>
#include <cstring>
using namespace std;
int d[501][501];
int a[501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    int start, end, del, add;
    cin >> start >> end >> del >> add;
    start -= 1;
    end -= 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= 1;
    }
    
    // 0행을 제외한 값을 Max로 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            d[i][j] = 1e9;
        }
    }
    
    // start 에서 0행의 1, 2, 3, .. , n-1 열로
    // 이동하는 최소 비용을 초기화
    for (int i = 0; i < m; i++) {
        // i열이 start와 같으면 비용은 0
        if (i == start) {
            d[0][i] = 0;
        // i열이 start와 다르면 사다리를 연결하는 비용으로 초기화
        } else {
            d[0][i] = abs(start - i) * add;
        }
    }
    
    // 1행부터 n행까지 start 에서 end 로 이동하는 최소 비용을 구한다. (행)
    for (int i = 1; i <= n; i++) {
        // 도착위치가 임의의 j 일때.. (열)
        for (int j = 0; j < m; j++) {
            // 시작하려는 위치가 임의의 k 일때.. (열)
            for (int k = 0; k < m; k++) {
                // k 열에서 j 열로 이동할 때 k 와 j 가 같고 (k == j)
                // 가로선이 존재 한다면 (a[i] == k || a[i]+1 == k)
                // 가로선을 제거해야 최소 비용이 나온다.
                // 왜? -> 가로선을 제거하지 않고 옆에 열로 넘어간다면 비용이 늘어나기 때문에
                if (k == j && (a[i] == k || a[i]+1 == k)) {
                    // 현재 최소 비용보다 사다리를 제거했을때 비용이 더 작다면
                    // 사다리를 제거했을때 비용으로 대입..
                    if (d[i][j] > d[i-1][k] + del) {
                        d[i][j] = d[i-1][k] + del;
                    }
                }
                // 나머지의 경우..
                // k 열에서 j 열로 이동할 때 이미 가로선이 놓아져 있으면
                // 가로선을 추가하는 개념이 아니기 때문에 abs(k-j)-1 을 해야 한다.
                // 놓아져 있는 가로선을 통과하는 비용은 0 이다.
                else if ((k <= a[i] && a[i] <= j-1) || (j <= a[i] && a[i] <= k-1)) {
                    // ex) 2 열에서 0 열로 이동하는데 중간에 가로선이 놓아져 있다면
                    // abs(k-j)-1 을 해줘야 한다.
                    if (d[i][j] > d[i-1][k] + (abs(k-j)-1)*add) {
                        d[i][j] = d[i-1][k] + (abs(k-j)-1)*add;
                    }
                }
                // k 열에서 j 열로 이동할 때 가로선이 존재 하지 않으면 모두 추가
                // 이동한 횟수 만큼 가로선을 추가하는 비용이 늘어난다.
                else {
                    if (d[i][j] > d[i-1][k] + abs(k-j)*add) {
                        d[i][j] = d[i-1][k] + abs(k-j)*add;
                    }
                }
            }
        }
    }
    
    cout << d[n][end] << '\n';
    return 0;
}
