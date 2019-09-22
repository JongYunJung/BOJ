// BOJ 10539 - 수빈이와 수열
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> arrB(n);
    for (int i = 0; i < n; i++) {
        cin >> arrB[i];
    }
    
    vector<int> arrA(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        arrA[i] = arrB[i] * (i+1) - sum;
        sum += arrA[i];
        cout << arrA[i] << " ";
    }
    cout << '\n';
    
    return 0;
}
