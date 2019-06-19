// BOJ 2490 - 윷놀이
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<char> answer = {'E', 'A', 'B', 'C', 'D' };
    for (int i = 0; i < 3; i++) {
        int zeroCount = 0;
        for (int j = 0; j < 4; j++) {
            int value;
            cin >> value;
            if (value == 0) zeroCount++;
        }
        cout << answer[zeroCount] << '\n';
    }
    
    return 0;
}
