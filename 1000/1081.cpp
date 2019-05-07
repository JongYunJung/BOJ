// BOJ 1081 - 합
// 수학 문제이다.
// 블로그를 참고하여 풀었지만, 아직도 이해를 못한 상태이다.
#include <iostream>
#include <vector>
using namespace std;

long long calc(int n) {
    vector<long long> cnt(10);
    int start = 1, end = n;
    int base = 1;
    
    while (start <= end) {
        while (end % 10 != 9 && start <= end) {
            int num = end;
            while (num > 0) {
                cnt[num % 10] += base;
                num /= 10;
            }
            end--;
        }
        
        if (start > end) break;
        
        while (start % 10 != 0 && start <= end) {
            int num = start;
            while (num > 0) {
                cnt[num % 10] += base;
                num /= 10;
            }
            start++;
        }
        
        start /= 10;
        end /= 10;
        
        for (int i = 0; i < 10; i++) {
            cnt[i] += (end - start + 1) * base;
        }
        
        base *= 10;
    }
    
    long long ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += (cnt[i] * i);
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int l, u;
    cin >> l >> u;
    cout << calc(u) - calc(l-1) << '\n';
    return 0;
}

