// BOJ 8320 - 직사각형을 만드는 방법
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j*j <= i; j++) {
            if (i % j == 0) answer++;
        }
    }
    
    cout << answer << '\n';
    return 0;
}
