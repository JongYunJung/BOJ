// BOJ 6549 - 히스토그램에서 가장 큰 직사각형
// 내가 풀기에는 너무 어려웠다.
// 스택을 활용한 풀이를 참고했는데, 풀이는 해당 블로그에 잘 나와있다.
// 참고한 블로그 : https://greeksharifa.github.io/ps/2018/07/07/PS-06549/
#include <iostream>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while (true) {
        int n;
        cin >> n;
        
        if (!n) break;
        
        stack<pair<int, int> > st;
        ll answer = 0;
        for (int i_index = 0; i_index <= n; i_index++) {
            int i_height;
            if (i_index < n) cin >> i_height;
            else i_height = -1;
            
            int left = i_index;
            while (!st.empty() && st.top().second > i_height) {
                answer = max(answer, (ll)(i_index - st.top().first) * st.top().second);
                left = st.top().first;
                st.pop();
            }
            st.push(make_pair(left, i_height));
        }
        
        cout << answer << '\n';
    }
    
    return 0;
}
