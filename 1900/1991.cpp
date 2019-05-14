// BOJ 1991 - 트리 순회
#include <iostream>
#include <vector>
using namespace std;
const int MAX_NODE = 26;
pair<char, char > tree[MAX_NODE];

void preorderTraversal(char node) {
    if (node == '.') return;
    cout << node;
    preorderTraversal(tree[node - 'A'].first);
    preorderTraversal(tree[node - 'A'].second);
}

void inorderTraversal(char node) {
    if (node == '.') return;
    inorderTraversal(tree[node - 'A'].first);
    cout << node;
    inorderTraversal(tree[node - 'A'].second);
}

void postorderTraversal(char node) {
    if (node == '.') return;
    postorderTraversal(tree[node - 'A'].first);
    postorderTraversal(tree[node - 'A'].second);
    cout << node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        tree[root - 'A'] = make_pair(left, right);
    }
    
    preorderTraversal('A');
    cout << '\n';
    inorderTraversal('A');
    cout << '\n';
    postorderTraversal('A');
    cout << '\n';
    
    return 0;
}
