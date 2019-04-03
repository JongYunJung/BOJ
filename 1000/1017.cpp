// BOJ 1017 - 소수 쌍
// 이분 매칭
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

const int MAX_V = 1001;
int visitCnt = 1;

vector<bool> isPrimeNum;
vector<int> adj[MAX_V];
vector<int> visited;
vector<int> aMatch;
vector<int> bMatch;

bool dfs(int a) {
    if (visited[a] == visitCnt) return false;
    visited[a] = visitCnt;
    
    for (int b : adj[a]) {
        if (!isPrimeNum[a+b]) continue;
        if (bMatch[b] == -1 || dfs(bMatch[b])) {
            aMatch[a] = b;
            bMatch[b] = a;
            return true;
        }
    }
    
    return false;
}

int bipartiteMatch(vector<int>& points) {
    visited = vector<int>(MAX_V);
    aMatch = vector<int>(MAX_V, -1);
    bMatch = vector<int>(MAX_V, -1);
    
    int size = 0;
    
    for (int a : points) {
        size += dfs(a);
        visitCnt += 1;
    }
    
    return size;
}

void eratosthenes(int n) {
    isPrimeNum = vector<bool>(n, true);
    int sqrtSize = sqrt(n);
    for (int i = 2; i < sqrtSize; i++) {
        if (!isPrimeNum[i]) continue;
        for (int j = i*i; j <= n; j+=i) {
            isPrimeNum[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    eratosthenes(MAX_V+MAX_V);
    
    int n;
    cin >> n;
    
    vector<int> odd;
    vector<int> even;
    int first = -1;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (first == -1) first = val;
        if (val % 2 == 1) odd.push_back(val);
        else even.push_back(val);
    }
    
    // 짝수 값 과 홀수 값이 같지 않으면 이분 매칭 되지 않음
    if (odd.size() != even.size()) {
        cout << -1 << '\n';
        return 0;
    }
    
    // 첫 번째 숫자가 홀수 또는 짝수일때의 기준으로 정점 연결하기
    int vertexSize = (int)odd.size();
    for (int i = 0; i < vertexSize; i++) {
        for (int j = 0; j < vertexSize; j++) {
            if (first % 2 == 1) adj[odd[i]].push_back(even[j]);
            else adj[even[i]].push_back(odd[j]);
        }
    }
    
    // 첫 번째 숫자의 간선을 모두 제거하고
    // 임의의 배열에 담기
    vector<int> firstLine;
    for (int f : adj[first]) firstLine.push_back(f);
    adj[first].clear();
    
    // 첫 번째 숫자에서 하나씩 연결하고 나머지 이분 매칭을 구한 뒤 다시 연결을 해제 한다.
    // 위의 과정 반복 (첫 번째 숫자가 연결되어 있는 수 만큼)
    vector<int> ans;
    for (int num : firstLine) {
        adj[first].push_back(num);
        int size = bipartiteMatch((first % 2 == 1) ? odd : even);
        if (odd.size() == size) ans.push_back(num);
        adj[first].pop_back();
    }
    
    if (ans.size() == 0) cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for (int a : ans) {
            cout << a << " ";
        }
    }
    
    cout << '\n';
    return 0;
}

