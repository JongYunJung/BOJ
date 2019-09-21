// BOJ 5618 - 공약수
#include <iostream>
#include <map>

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
    
    int n;
    cin >> n;
    
    // 유클리드 호제법 활용하기
    int a;
    cin >> a;
    for (int i = 1; i < n; i++) {
        int b;
        cin >> b;
        if (a < b) swap(a, b);
        a = GCD(a, b);
    }
    
    for (int i = 1; i <= a; i++) {
        if (a % i == 0) cout << i << '\n';
    }

    // 내가 생각한대로 푼 방법 - 2124KB, 692ms
//    map<int, int> mp;
//    for (int i = 0; i < n; i++) {
//        int value;
//        cin >> value;
//        for (int num = 1; num <= value; num++) {
//            if (value % num == 0) {
//                if (mp.find(num) == mp.end()) {
//                    mp[num] = 1;
//                } else {
//                    mp[num]++;
//                }
//            }
//        }
//    }
//
//    for (auto p : mp) {
//        if (p.second == n) cout << p.first << '\n';
//    }
    
    return 0;
}
