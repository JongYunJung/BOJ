// BOJ 15438 - 최소 편집
// Edit Distance 알고리즘
// DP 방식
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int cache[1001][1001];
string src, dst;

int go(int row, int col) {
    if (row < 0 && col < 0) return 0;
    if (cache[row][col] != -1) return cache[row][col];
    int& result = cache[row][col] = 0;
    if (dst[row] == src[col]) result = go(row - 1, col - 1);
    else result = min(go(row - 1, col), min(go(row, col - 1), go(row - 1, col - 1))) + 1;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> src >> dst;
    
    src = " " + src;
    dst = " " + dst;
    
    int srcSize = (int)src.size();
    int dstSize = (int)dst.size();
    
    memset(cache, -1, sizeof(cache));
    
    for (int i = 0; i < srcSize; i++) cache[0][i] = i;
    for (int i = 0; i < dstSize; i++) cache[i][0] = i;
    
    cout << go(dstSize - 1, srcSize - 1) << '\n';
    
    return 0;
}
