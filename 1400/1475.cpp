// BOJ - 1475 방번호
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    string str = to_string(n);
    
    vector<int> check(9);
    for (int i = 0; i < str.length(); i++) {
        int num = stoi(str.substr(i, 1));
        if (num == 9) num = 6;
        check[num] += 1;
    }
    
    int ans = 0;
    check[6] = (check[6] + 1) / 2;
    for (int i = 0; i < check.size(); i++) {
        ans = max(ans, check[i]);
    }
    
    cout << ans << '\n';
    return 0;
}
