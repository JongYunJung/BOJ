// BOJ 10830 - 행렬 제곱
// 문제 해결 포인트
// 1. 행렬의 제곱을 처리하는 부분
// 2. 분할 정복
// 3. 분할 정복시 짝수, 홀수 처리를 해야한다.
// 4. 메모이제이션 기법 사용
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef vector<long long> ARRAY_1D;
typedef vector<vector<long long> > ARRAY_2D;
typedef unordered_map<long long, ARRAY_2D> UN_MAP;

UN_MAP cache;
ARRAY_2D init;

const int MOD = 1000;

ARRAY_2D cal(ARRAY_2D& a, ARRAY_2D& b) {
    ARRAY_2D answer(a.size(), ARRAY_1D(a.size(), 0));
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer.size(); j++) {
            for (int k = 0; k < answer.size(); k++) {
                answer[i][j] += a[i][k] * b[k][j];
            }
            answer[i][j] %= MOD;
        }
    }
    return answer;
}

ARRAY_2D go(long long b) {
    if (b == 1 && !cache.count(b))
        return cache[1] = init;
    
    if (cache.count(b))
        return cache[b];
    
    ARRAY_2D ans1 = go(b / 2);
    ARRAY_2D ans2 = go(b / 2 + b % 2);
    
    return cache[b] = cal(ans1, ans2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    long long b;
    cin >> n >> b;
    
    init = ARRAY_2D(n, ARRAY_1D(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> init[i][j];
            init[i][j] %= MOD;
        }
    }
    
    ARRAY_2D answer = go(b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << answer[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}
