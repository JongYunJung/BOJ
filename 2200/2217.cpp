// BOJ 2217 - 로프
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<long long> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    
    // 오름차순으로 정렬하고..
    sort(k.begin(), k.end());
    
    // 첫 번째 로프부터 마지막 로프까지 루프를 돌면서
    // 최대 중량을 찾는다.
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        long long weight = k[i];
        for (int j = i+1; j < n; j++) {
            weight += k[i];
        }
        answer = max(answer, weight);
    }
    
    cout << answer << '\n';
    
    return 0;
}
