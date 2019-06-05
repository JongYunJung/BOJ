// BOJ 2446 - 별 찍기 - 9
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= 2*n-1; i++) {
        for (int j = 0; j < n-abs(n-i)-1; j++) cout << " ";
        for (int j = 0; j < 2*abs(n-i)+1; j++) cout << "*";
        cout << '\n';
    }
    
    return 0;
}
