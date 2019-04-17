// BOJ 1181 - 단어 정렬
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> str;
    unordered_map<string, bool> check;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (check.count(s) == 0) {
            check[s] = true;
            str.push_back(s);
        }
    }
    
    sort(str.begin(), str.end(), [](const string& a, const string& b) {
        size_t aLen = a.length();
        size_t bLen = b.length();
        if (aLen == bLen) {
            for (size_t i = 0; i < aLen; i++) {
                if (a[i] == b[i]) continue;
                else if (a[i] < b[i]) return true;
                else return false;
            }
        } else if (aLen < bLen){
            return true;
        }
        return false;
    });
    
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << '\n';
    }
    
    return 0;
}
