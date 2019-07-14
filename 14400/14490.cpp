// BOJ 14490 - 백대열
// 최대 공약수의 값으로 값들을 나눠주면 된다.
// 최대 공약수는 '유클리드 호제법'을 이용해서 구한다.
#include <iostream>
#include <string>

using namespace std;

int GCD(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    size_t index = s.find(':');
    int a = stoi(s.substr(0, index));
    int b = stoi(s.substr(index + 1, s.length() - (index + 1)));
    
    int tempA = a, tempB = b;
    if (tempA < tempB) swap(tempA, tempB);
    
    int gcd = GCD(tempA, tempB);
    cout << (a / gcd) << ":" << (b / gcd) << '\n';
    
    return 0;
}
