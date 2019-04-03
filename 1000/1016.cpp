// BOJ 1016 - 제곱 ㄴㄴ 수
#include <iostream>
using namespace std;
bool isSqr[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long min, max;
    cin >> min >> max;
    
    for (long long i = 2; i*i <= max; i++) {
        long long start = min / (i * i);
        if (start * i * i != min) start += 1;
        for (long long j = start; i*i*j <= max; j++) {
            isSqr[i * i * j - min] = true;
        }
    }
    
    int count = 0;
    for (int i = 0; i < max-min+1; i++) {
        if (!isSqr[i]) count += 1;
    }
    
    cout << count << '\n';
    return 0;
}
