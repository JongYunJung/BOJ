// BOJ 1009 분산 처리
// 각 숫자에서 제곱을 진행할 때마다 일의 자리수의 패턴이 존재한다.
// 이 핵심을 가지고 문제를 해결했음
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // 각 숫자에서 제곱시 나오는 패턴 미리 구하기
    vector<int> numOfCase[10];
    numOfCase[0].push_back(10);
    for (int num = 1; num < 10; num++) {
        numOfCase[num%10].push_back(num % 10);
        int temp = num * num;
        while (temp % 10 != (num % 10)) {
            numOfCase[num%10].push_back(temp % 10);
            temp *= num;
        }
    }
    
    int tc;
    cin >> tc;
    while (tc--) {
        int a, b;
        cin >> a >> b;
        int cSize = (int)numOfCase[a%10].size();
        if (b % cSize == 0) cout << numOfCase[a%10][cSize-1] << '\n';
        else cout << numOfCase[a%10][(b%cSize)-1] << '\n';
    }
    
    return 0;
}
