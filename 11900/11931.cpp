// BOJ 11931 - 수 정렬하기 4
// Counting Sort
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<bool> > count(2, vector<bool>(MAX+1));
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (value >= 0) count[0][value] = true;
        else count[1][abs(value)] = true;
    }
    
    for (int num = MAX; num >= 0; num--) {
        if (count[0][num]) cout << num << '\n';
    }
    
    for (int num = -1; num >= -MAX; num--) {
        if (count[1][abs(num)]) cout << num << '\n';
    }
    
    return 0;
}
