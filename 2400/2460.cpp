// BOJ 2460 - 지능형 기차 2
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int ans = 0, sum = 0;
    for (int i = 0; i < 10; i++) {
        int in, out;
        cin >> in >> out;
        sum = sum - in + out;
        ans = max(ans, sum);
    }
    
    cout << ans << '\n';
    return 0;
}
