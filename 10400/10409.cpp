// BOJ 10409 - 서버
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, t;
    cin >> n >> t;
    
    int sum = 0;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int et;
        cin >> et;
        if (sum + et <= t) {
            sum += et;
            answer++;
        } else break;
    }
    
    cout << answer << '\n';
    return 0;
}
