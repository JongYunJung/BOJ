// BOJ 1966 - 프린터 큐
// 우선순위 큐를 사용 (값이 높은 것부터 앞에 있음)
// 이를 이용해서 중요도를 비교한다.
// 중요도가 같지 않으면, (중요도, 인덱스)를 큐에 다시 삽입한다.
// 중요도가 같으면, 현재 인덱스와 찾고 싶은 인덱스가 같은지 비교하여 결과를 도출하면 된다.
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        
        queue<pair<int, int> > q;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int imt;
            cin >> imt;
            q.push(make_pair(i, imt));
            pq.push(imt);
        }
        
        int count = 0;
        while (!q.empty()) {
            int index = q.front().first;
            int importance = q.front().second;
            q.pop();
            
            if (pq.top() == importance) {
                pq.pop();
                count++;
                if (index == m) {
                    cout << count << '\n';
                    break;
                }
            } else q.push(make_pair(index, importance));
        }
    }
    
    return 0;
}
