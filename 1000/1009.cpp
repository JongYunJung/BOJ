// BOJ 1009 분산 처리
// 각 숫자에서 제곱을 진행할 때마다 일의 자리수의 패턴이 존재한다.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // 각 숫자에서 제곱시 나오는 패턴 미리 구하기
    vector<int> pattern[10];
    pattern[0].push_back(10);
    for (int num = 1; num < 10; num++) {
        pattern[num].push_back(num);
        int tempNum = num * num;
        while (tempNum % 10 != num) {
            pattern[num].push_back(tempNum % 10);
            tempNum *= num;
        }
    }
    
    int tc;
    cin >> tc;
    while (tc--) {
        int a, b;
        cin >> a >> b;
        a %= 10;
        int pSize = (int)pattern[a].size();
        if (b % pSize == 0) cout << pattern[a][pSize-1];
        else cout << pattern[a][b%pSize-1];
        cout << '\n';
    }
    
    return 0;
}
