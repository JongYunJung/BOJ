// BOJ 3015 - 오아시스 재결합
// 어려운 문제였다..
// https://jaimemin.tistory.com/831 블로그를 참고해서 해결함
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    stack<pair<int, int> > st;
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;
        
        while (!st.empty() && st.top().first < height) {
            answer += st.top().second;
            st.pop();
        }
        
        if (st.empty()) st.push(make_pair(height, 1));
        else {
            if (st.top().first == height) {
                pair<int, int> current = st.top();
                st.pop();
                
                answer += current.second;
                // 스택이 비어있지 않으면 가장 큰 사람과 쌍을 이루기 때문에 +1 증가
                if (!st.empty()) answer++;
                // 연속해서 같은 키를 가진 사람이 나오므로 +1 증가
                current.second++;
                st.push(current);
            } else {
                st.push(make_pair(height, 1));
                answer++;
            }
        }
    }
    
    cout << answer << '\n';
    return 0;
}
