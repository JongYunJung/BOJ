// BOJ 10816 - 숫자카드 2
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    unordered_map<int, int> hm;
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        if (hm.find(key) == hm.end()) {
            hm[key] = 1;
        } else {
            hm[key] += 1;
        }
    }
    
    vector<int> a;
    for (auto kv : hm) a.push_back(kv.first);
    sort(a.begin(), a.end());
    
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    
    for (int i = 0; i < b.size(); i++) {
        bool find = false;
        int key = b[i];
        int left = 0, right = (int)a.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] > key) {
                right = mid - 1;
            } else if (a[mid] < key) {
                left = mid + 1;
            } else {
                find = true;
                break;
            }
        }
        if (find) cout << hm[key];
        else cout << 0;
        cout << " ";
    }
    
    cout << '\n';
    return 0;
}

