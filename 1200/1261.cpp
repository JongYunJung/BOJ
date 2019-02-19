// BOJ - 1261 알고스팟
#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;


const int nINF = 10000;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

vector<vector<int> > map;

int N, M;

int Dijkstra(int y, int x)
{
    vector<vector<int> > cost(N, vector<int>(M, nINF));
    
    cost[y][x] = 0;
    
    priority_queue<tuple<int, int, int> > pq;
    
    pq.push(make_tuple(0, y, x));
    
    while (!pq.empty())
    {
        int curCost, curY, curX;
        curCost = -get<0>(pq.top());
        tie(ignore, curY, curX) = pq.top();
        pq.pop();
        
        if (curY == (N-1) && curX == (M-1))
            return cost[curY][curX];
        
        for (int d = 0; d < 4; ++d)
        {
            int nextY = curY + dy[d];
            int nextX = curX + dx[d];
            
            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
                continue;
            
            int nextCost = curCost + map[nextY][nextX];
            
            if (cost[nextY][nextX] > nextCost)
            {
                cost[nextY][nextX] = nextCost;
                pq.push(make_tuple(-nextCost, nextY, nextX));
            }
        }
    }
    
    return -1;
}

int main()
{
    scanf("%d %d", &M, &N);
    
    map = vector<vector<int> >(N, vector<int>(M, -1));
    
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
            scanf("%1d", &map[y][x]);
    }
    
    printf("%d\n", Dijkstra(0, 0));
    
    return 0;
}



