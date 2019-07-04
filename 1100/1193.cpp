// BOJ 1193 - 분수 찾기
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << "/" << 1 << '\n';
        return 0;
    }
    
    long long ordered = 0;
    int sum = 0;
    int num = 0;
    while (true) {
        sum++;
        ordered += num;
        if (ordered >= n) break;
        num++;
    }
    
    int child = 1, parent = 1;
    if (sum % 2) child = sum - 1;
    else parent = sum - 1;
    
    while (true) {
        if (ordered == n) break;
        if (sum % 2) {
            parent++;
            child--;
        } else {
            parent--;
            child++;
        }
        ordered--;
    }
    
    cout << child << "/" << parent << '\n';
    return 0;
}
