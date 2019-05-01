// BOJ 9372 - 상근이의 여행
// 최소 스패닝 트리 (Minimum Spanning Tree, MST)
// MST 는 정점(N)-1 개의 간선으로 이루어져 있다.
// 자세하게 공부해보자.
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
        }
        
        cout << n-1 << '\n';
    }
    
    return 0;
}

