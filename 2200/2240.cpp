// BOJ 2240 - 자두 나무
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SECOND = 1000;
const int MAX_MOVE = 31;

int dp[3][MAX_SECOND][MAX_MOVE];
int plum[MAX_SECOND];
int t, w;

int go(int tree, int second, int move) {
    if (second == t) return 0;
    
    int& ans = dp[tree][second][move];
    if (ans != -1) return ans;
    
    if (plum[second] == tree) { // 현재 나무에서 자두가 떨어지는 경우
        if (move < w) {
            ans = go(tree, second+1, move) + 1;
            ans = max(ans, go(3-tree, second+1, move+1));
        } else {
            ans = go(tree, second+1, move) + 1;
        }
    } else { // 반대 나무에서 떨어지는 경우
        if (move < w) {
            ans = go(tree, second+1, move);
            ans = max(ans, go(3-tree, second+1, move+1) + 1);
        } else {
            ans = go(tree, second+1, move);
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t >> w;
    for (int i = 0; i < t; i++) {
        cin >> plum[i];
    }
    
    memset(dp, -1, sizeof(dp));
    cout << go(1, 0, 0) << '\n';
    return 0;
}
