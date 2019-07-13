// BOJ 15438 - 최소 편집
// Edit Distance 알고리즘
// DP 방식
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string src, dst;
int cache[1001][1001];

int go(int r, int c) {
    if (r < 0 && c < 0) return 0;
    if (cache[r][c] != -1) return cache[r][c];
    
    int& result = cache[r][c] = 0;
    if (src[r] == dst[c]) result = go(r-1, c-1);
    else result = 1 + min(min(go(r-1, c), go(r, c-1)), go(r-1, c-1));
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> src >> dst;
    
    src = " " + src;
    dst = " " + dst;
    
    int srcSize = (int)src.size();
    int dstSize = (int)dst.size();
    
    for (int i = 0; i < srcSize; i++) cache[i][0] = i;
    for (int i = 0; i < dstSize; i++) cache[0][i] = i;
    
    cout << go(srcSize-1, dstSize-1) << '\n';
    
    return 0;
}
