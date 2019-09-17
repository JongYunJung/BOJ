// BOJ 8979 - 올림픽
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

bool compare(tuple<int, int, int, int>& a, tuple<int, int, int, int>& b) {
    int aGold, aSilver, aBronze;
    int bGold, bSilver, bBronze;
    tie(ignore, aGold, aSilver, aBronze) = a;
    tie(ignore, bGold, bSilver, bBronze) = b;
    
    if (aGold == bGold) {
        if (aSilver == bSilver) {
            return aBronze > bBronze;
        }
        return aSilver > bSilver;
    }
    return aGold > bGold;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<tuple<int, int, int, int> > info(n);
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        info[i] = make_tuple(a, b, c, d);
    }
    
    sort(info.begin(), info.end(), compare);
    
    
    vector<pair<int, int> > answers(n);
    int rank = 1;
    int i = 0;
    while (i < n) {
        int n1, g1, s1, b1;
        tie(n1, g1, s1, b1) = info[i];
        
        answers[i].first = n1;
        answers[i].second = rank;
        
        int cnt = 1;
        int j = i + 1;
        while (j < n) {
            int n2, g2, s2, b2;
            tie(n2, g2, s2, b2) = info[j];
            if (g1 == g2) {
                if (s1 == s2) {
                    if (b1 == b2) {
                        answers[j].first = n2;
                        answers[j].second = rank;
                        cnt++;
                        j++;
                    } else break;
                } else break;
            } else break;
        }
        
        i = j;
        rank += cnt;
    }
    
    for (auto p : answers) {
        if (p.first == k) {
            cout << p.second << '\n';
            break;
        }
    }
    
    return 0;
}
