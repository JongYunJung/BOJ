// BOJ 11279 - 최대 힙
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    priority_queue<int> pq;
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        
        if (value == 0) {
            if (pq.empty()) {
                cout << "0" << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(value);
        }
    }
    
    return 0;
}
