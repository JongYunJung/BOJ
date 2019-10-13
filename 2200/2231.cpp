// BOJ 2231 - 분해합
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    bool find = false;
    const int MAX = 1e6;
    for (int num = 1; num <= MAX; num++) {
        int sum = num;
        int tempNum = num;
        while (tempNum != 0) {
            sum += tempNum % 10;
            tempNum /= 10;
        }
        if (sum == n) {
            cout << num << '\n';
            find = true;
            break;
        }
    }
    
    if (!find) {
        cout << 0 << '\n';
    }
    
    return 0;
}
