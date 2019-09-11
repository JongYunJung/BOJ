// BOJ 1023 - 괄호 문자열
// 내가 푼 방식이 메모리 초과가 나왔다.
// 블로그를 참고했다. https://sgc109.tistory.com/128
// 풀이는 다음과 같다. (간단 요약)
// 1. dp 방법으로 괄호 문자열의 갯수를 구하는 코드를 구현하기
// 2. 반대로 괄호 ㄴㄴ 문자열은 어떻게 구할까?
//      1) if (open > 0) 조건 지워야 한다. 괄호 문자열을 구할 때,
//         열린 괄호가 닫힌 괄호보다 많아지는 순간 무조건 괄호 문자열이 아니게 되므로 조건을 붙인 것
//         하지만 괄호 ㄴㄴ 문자열에서는 그런 경우도 세워 주어야 하기 때문에 조건문을 지워 준다.
//      2), 3) 은 내가 이해하지 못했다. 블로그를 참고하기
// 3. 괄호 ㄴㄴ 문자열은 어떻게 찾을까?
#include <iostream>
#include <cstring>

using namespace std;

const long long INF = 0x3c3c3c3c3c3c3c3c;
long long dp[51][101][2];
long long k;
int n;

long long go(int pos, int cnt, int wrong) {
    if (pos == n) return wrong || cnt != 0;
    
    long long& cache = dp[pos][cnt+n][wrong];
    if (cache != INF) return cache;
    
    cache = go(pos+1, cnt+1, wrong);
    cache += go(pos+1, cnt-1, wrong || cnt <= 0);
    
    return cache;
}

void go2(int pos, int cnt, int wrong, long long kk) {
    if (pos == n) return;
    if (dp[pos+1][cnt+1+n][wrong] >= kk) {
        if (pos == n-1 && kk == 2) cout << ')';
        else cout << '(';
        go2(pos+1, cnt+1, wrong, kk);
    } else {
        cout << ')';
        go2(pos+1, cnt-1, wrong || cnt <= 0, kk-dp[pos+1][cnt+1+n][wrong]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dp, 0x3c, sizeof(dp));
    
    cin >> n >> k;
    if (k + 1 > go(0, 0, 0)) {
        cout << -1 << '\n';
        return 0;
    }
    
    go2(0, 0, 0, k+1);
    cout << '\n';
    
    return 0;
}
