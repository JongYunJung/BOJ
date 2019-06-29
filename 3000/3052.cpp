// BOJ 3052 - 나머지
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    set<int> s;
    for (int i = 0; i < 10; i++) {
        int value;
        cin >> value;
        value %= 42;
        if (s.count(value) == 0) s.insert(value);
    }
    
    cout << s.size() << '\n';
    return 0;
}
