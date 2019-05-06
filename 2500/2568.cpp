// BOJ 2568 - 전깃줄 - 2
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

const int MAX_NUM = 5e5 + 1;
const int MAX_CNT = 1e5 + 1;
vector<pair<int, int> > connect;
pair<int, int> tracking[MAX_CNT];
vector<bool> visited(MAX_NUM);
vector<int> lis(MAX_CNT);

int my_lower_bound(int lis_index, int target) {
    int start = 0, end = lis_index;
    while (start < end) {
        int mid = (start + end) / 2;
        if (lis[mid] < target) start = mid + 1;
        else end = mid;
    }
    return end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int index, value;
        cin >> index >> value;
        connect.push_back(make_pair(index, value));
        visited[index] = true;
    }
    sort(connect.begin(), connect.end());
    
    int j = 0;
    lis[j] = connect[0].second;
    tracking[0] = {0, connect[0].first};
    for (int i = 1; i < n; i++) {
        if (lis[j] < connect[i].second) {
            lis[++j] = connect[i].second;
            tracking[i] = {j, connect[i].first};
        } else {
            int ii = my_lower_bound(j, connect[i].second);
            lis[ii] = connect[i].second;
            tracking[i] = {ii, connect[i].first};
        }
    }
    cout << n - (j + 1) << '\n';
    
    stack<int> s;
    int lis_Index = j;
    for (int i = n-1; i >= 0; i--) {
        if (tracking[i].first == lis_Index) {
            s.push(tracking[i].second);
            lis_Index--;
        }
    }
    
    while (!s.empty()) {
        visited[s.top()] = false;
        s.pop();
    }
    
    for (int i = 1; i <= 5e5; i++) {
        if(visited[i]) cout << i << '\n';
    }
    return 0;
}

