// BOJ 11659 구간 합 구하기 4
#include <iostream>
using namespace std;
int prefix_sum[100001]; // 누적합

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> prefix_sum[i];
        prefix_sum[i] += prefix_sum[i-1];
    }
    
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << prefix_sum[e] - prefix_sum[s-1] << '\n';
    }
    
    return 0;
}
