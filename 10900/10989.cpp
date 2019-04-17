// BOJ - 10989 수 정렬하기 3
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    const int MAX = 10001;
    vector<int> count(MAX);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        count[num]++;
    }
    
    for (int num = 1; num < MAX; num++) {
        while (count[num]--) {
            cout << num << '\n';
        }
    }
    
    return 0;
}

