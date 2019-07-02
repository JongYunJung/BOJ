// BOJ 2292 - 벌집
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    
    int answer = 2;
    int startNum = 7;
    while (n > startNum) {
        startNum = 6 * answer + startNum;
        answer++;
    }
    
    cout << answer << '\n';
    return 0;
}
