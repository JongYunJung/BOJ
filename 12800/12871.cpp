// BOJ 12871 - 무한 문자열
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;
    
    // 문자열의 길이가 같아질 때까지 계속 합쳐본다.
    // ex) s.length 가 49 거나 t.length 가 50 이면 -> 2450 길이의 문자열밖에 나오지 않음 (대략 50번 수행)
    // ex) s.length 가 50 이거나 t.length 가 49 여도 -> 2450 길이의 문자열 (대략 50번 수행)
    // ex) s.length 가 1, t.length가 50 이면 -> (50번 수행)
    string S = s, T = t;
    while (S.length() != T.length()) {
        if (S.length() < T.length()) {
            S += s;
        } else {
            T += t;
        }
    }
    
    cout << ((S == T) ? 1 : 0) << '\n';
    return 0;
}
