// BOJ - 2108 통계학
// 정렬 문제
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> a;
    double sum = 0.f;
    
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        a.push_back(key);
        sum += key;
    }
    
    sort(a.begin(), a.end());
    
    int avg = floor((sum / n) + 0.5f);
    cout << avg << '\n';
    cout << a[n/2] << '\n';
    
    vector<pair<int, int> > frequency;
    for (int i = 0; i < n; i++) {
        if (frequency.empty()) {
            frequency.push_back(make_pair(a[i], 1));
            continue;
        }
        
        if (frequency.back().first == a[i]) {
            int cnt = frequency.back().second + 1;
            frequency.pop_back();
            frequency.push_back(make_pair(a[i], cnt));
        } else {
            frequency.push_back(make_pair(a[i], 1));
        }
    }
    
    sort(frequency.begin(), frequency.end(), []
         (const pair<int, int>& a, const pair<int, int>& b) {
             if (a.second == b.second) {
                 return a.first < b.first;
             }
             return a.second > b.second;
         });
    
    if (frequency[0].second == frequency[1].second) {
        cout << frequency[1].first;
    } else {
        cout << frequency[0].first;
    }
    cout << '\n';
    cout << a.back() - a.front() << '\n';
    return 0;
}

