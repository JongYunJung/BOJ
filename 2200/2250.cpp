// BOJ 2250 - 트리의 높이와 너비
#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x7FFFFFFF;
const int MAX = 10001;
int nodeIndex = 1;

pair<int, int> tree[MAX];
vector<int> high;
vector<int> low;

// 중위 순회 (inOrder)
void dfs(int nodeNum, int level) {
    if (tree[nodeNum].first > 0) {
        dfs(tree[nodeNum].first, level+1);
    }
    
    low[level] = min(low[level], nodeIndex);
    high[level] = max(high[level], nodeIndex++);
    
    if (tree[nodeNum].second > 0) {
        dfs(tree[nodeNum].second, level+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    // 단순히 루트 노드를 찾기 위한 배열
    vector<int> node(n+1);
    for (int i = 0; i < n; i++) {
        int parent, childLeft, childRight;
        cin >> parent >> childLeft >> childRight;
        
        node[parent]++;
        
        if (childLeft != -1) node[childLeft]++;
        if (childRight != -1) node[childRight]++;
        
        tree[parent].first = childLeft;
        tree[parent].second = childRight;
    }
    
    // 루트 노드가 무조건 1번은 아니라고 한다.
    // 왜?......... 문제에 보면 그런 조건은 없는데 그냥
    // 노드 번호 1번을 생략하고 2번부터 할 수도 있다는 뜻인건가?
    // 일단 루트 노드를 찾는다. node배열에서 1인 원소의 값이 루트 노드이다.
    int root = 0;
    for (int i = 1; i < node.size(); i++) {
        if (node[i] == 1) root = i;
    }
    
    high = vector<int>(n+1);
    low = vector<int>(n+1, INF);
    dfs(root, 1);
    
    // 가장 큰 너비와 높이를 찾는다.
    int level = 1;
    int width = high[1] - low[1] + 1;
    for (int i = 2; i < n+1; i++) {
        int value = high[i] - low[i] + 1;
        if (width < value) {
            width = value;
            level = i;
        }
    }
    
    cout << level << " " << width << '\n';
    return 0;
}
