// BOJ 11268 - 절댓값 힙
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    priority_queue<pair<int, int> > pq;
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        
        if (!value && pq.empty()) {
            cout << 0 << '\n';
        } else if (!value) {
            cout << -pq.top().second << '\n';
            pq.pop();
        } else {
            pq.push(make_pair(-abs(value), -value));
        }
    }
    
    return 0;
}
