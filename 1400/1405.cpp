// BOJ 1405 - 미친 로봇
#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int areaSize = 29;
const int dirCnt = 4;

vector<vector<bool> > visited;
vector<double> percentage;

double answer = 0.f;
int n;

void dfs(int y, int x, int depth, double curPercentage) {
    if (depth == n) {
        answer += curPercentage;
        return;
    }
    
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        
        if (!visited[ny][nx]) {
            visited[ny][nx] = true;
            dfs(ny, nx, depth+1, curPercentage * percentage[d]);
            visited[ny][nx] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    visited = vector<vector<bool> >(areaSize, vector<bool>(areaSize));
    percentage = vector<double>(dirCnt);
    
    cin >> n;
    
    for (int i = 0; i < dirCnt; i++) {
        cin >> percentage[i];
        percentage[i] *= 0.01;
    }
    
    visited[14][14] = true;
    dfs(14, 14, 0, 1.0);
    
    cout << fixed;
    cout.precision(10);
    cout << answer << '\n';
    
    return 0;
}
