// BOJ 1062
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int count(vector<int>& words, int mask) {
    int cnt = 0;
    for (int word : words) {
        if ((word & ((1 << 26)-1-mask)) == 0) {
            cnt++;
        }
    }
    return cnt;
}

int go(vector<int>& words, int index, int k, int mask) {
    if (k < 0)
        return 0;
    
    if (index == 26)
        return count(words, mask);
    
    int ans = 0;
    // 글자를 배운 경우
    ans = max(ans, go(words, index+1, k-1, mask | (1 << index)));
    // 글자를 배우지 않은 경우
    // a, c, i, n, t 알파벳은 무조건 배워야 함
    if (index != 'a'-'a' && index != 'c'-'a' && index != 'i'-'a'
        && index != 'n'-'a' && index != 't'-'a') {
        ans = max(ans, go(words, index+1, k, mask));
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<int> words(n);
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        for (char alphabet : word) {
            words[i] |= (1 << (alphabet - 'a'));
        }
    }
    
    cout << go(words, 0, k, 0) << '\n';
    return 0;
}
