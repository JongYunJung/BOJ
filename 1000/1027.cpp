// BOJ 1027 - 고층 건물
// 건물 사이의 길이를 구하는 수학 문제
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        double t = -9e9, m;
        for (int j = i+1; j < n; j++) {
            m = (double)(a[j] - a[i]) / (j - i);
            if (m > t) {
                t = m;
                b[i]++;
                b[j]++;
            }
        }
    }
    
    cout << *max_element(b.begin(), b.end()) << '\n';
    return 0;
}
