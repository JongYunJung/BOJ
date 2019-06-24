// BOJ 10820 - 문자열 분석
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    while(getline(cin, s, '\n')) {
        vector<int> counts(4);
        for (char ch : s) {
            if ('a' <= ch && ch <= 'z') counts[0]++;
            else if ('A' <= ch && ch <= 'Z') counts[1]++;
            else if ('0' <= ch && ch <= '9') counts[2]++;
            else if (ch == ' ') counts[3]++;
        }
        
        for (int cnt : counts) cout << cnt << " ";
        cout << '\n';
    }
    
    return 0;
}
