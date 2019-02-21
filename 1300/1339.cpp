// BOJ 1339 - 단어 수학
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int cal(vector<string>& a, vector<char>& letters, vector<int>& perm) {
    char alpha[256];
    for (size_t i = 0; i < letters.size(); i++) {
        alpha[letters[i]] = perm[i];
    }
    
    int sum = 0;
    for (string s : a) {
        int num = 0;
        for (char c : s) {
            num = num * 10 + alpha[c];
        }
        sum += num;
    }
    
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<string> a(n);
    vector<char> letters;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (char c : a[i]) {
            letters.push_back(c);
        }
    }
    sort(letters.begin(), letters.end());
    letters.erase(unique(letters.begin(), letters.end()), letters.end());
    
    vector<int> perm;
    for(size_t i = 0; i < letters.size(); i++) {
        perm.push_back(9-i);
    }
    
    int ans = 0;
    do
    {
        int ret = cal(a, letters, perm);
        ans = max(ans, ret);
    } while (prev_permutation(perm.begin(), perm.end()));
    cout << ans << '\n';
    
    return 0;
}
