// BOJ 11365 - !밀비 급일
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while (true) {
        string str;
        getline(cin, str);
        if (str == "END") break;
        reverse(str.begin(), str.end());
        cout << str << '\n';
    }
    
    return 0;
}
