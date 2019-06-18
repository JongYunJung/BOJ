// BOJ 1158 - 조세퍼스 문제
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    queue<int> q;
    for (int num = 1; num <= n; num++) q.push(num);
    
    cout << "<";
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < k-1; j++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">" << '\n';
    
    return 0;
}
