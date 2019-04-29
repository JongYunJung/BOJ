// BOJ 1075 - 나누기
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, f;
    cin >> n >> f;
    
    int temp = (n / 100) * 100;
    for (int i = 0; i < 100; i++) {
        if ((temp + i) % f == 0) {
            if (i < 10) cout << "0" + to_string(i);
            else cout << to_string(i);
            cout << '\n';
            break;
        }
    }
    
    return 0;
}

