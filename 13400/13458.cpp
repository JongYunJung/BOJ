// BOJ 13458 - 시험 감독
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // 입력
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b, c;
    cin >> b >> c;
    
    // 감독관이 감시할 수 있는 인원 구하기..
    // 총 감독관 b 명 감시 가능
    // 부 감독관 c 명 감시 가능
    long long people = 0;
    for (int i = 0; i < n; i++) {
        // 1. 총 감독관
        ++people;
        a[i] -= b;
        // 2. 부 감독관
        // - 값이 나오면 0으로 처리해주기
        if (a[i] < 0) {
            a[i] = 0;
        }
        // 감시 가능한 인원을 나누면 부 감독관 인원을 구할 수 있다.
        people += (a[i] / c);
        // 나머지가 0이 아니면 부 감독관이 1명 더 필요하므로 +1 처리
        if (a[i] % c != 0) {
            ++people;
        }
    }
 
    cout << people << '\n';
    return 0;
}
