// BOJ 1773 - 폭죽쇼
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, c;
    cin >> n >> c;
    
    vector<int> cycle(n);
    for (int i = 0; i < n; i++) {
        cin >> cycle[i];
    }
    
    sort(cycle.begin(), cycle.end());

    vector<bool> check(c+1);
    int answer = 0;
    for (int i = 0; i < n; i++) {
        // 같은 주기가 있는 경우를 대비하여 예외처리함
        // 예를들어 2, 2, 4 가 있으면, 맨 처음 2에 대한 작업을 하고나서
        // 두 번째 2에 대한 작업을 할 필요가 없고, 2의 배수인 경우에도 이미 다 처리를 해놨기 때문에
        // 굳이 중복된 작업을 할 필요가 없다.
        if (check[cycle[i]]) continue;
        int sec = cycle[i];
        while (sec <= c) {
            if (!check[sec]) {
                check[sec] = true;
                answer++;
            }
            sec += cycle[i];
        }
    }
    
    cout << answer << '\n';
    return 0;
}
