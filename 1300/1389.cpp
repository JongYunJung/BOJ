// BOJ 1389 - 케빈 베이컨의 6단계 법칙
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
vector<int> dist, totalDist;

int N, M, step = 987654321;
// 플로이드 와샬

// 다익스트라

// 일반 BFS
void BFS(int start)
{
    dist = vector<int>(N+1, -1);
    dist[start] = 0;
    
    queue<int> qe;
    qe.push(start);
    
    while (!qe.empty())
    {
        int here = qe.front();
        qe.pop();
        
        for (int v = 1; v < N+1; ++v)
        {
            int there = adj[here][v];
            
            if (dist[there] == -1)
            {
                dist[there] = dist[here] + 1;
                qe.push(there);
            }
        }
    }
    
    for (int u = 1; u < N+1; ++u)
        totalDist[start] += dist[u];
}

int main()
{
    scanf("%d %d", &N, &M);
    
    adj = vector<vector<int> >(N+1, vector<int>(N+1, 0));
    totalDist = vector<int>(N+1, 0);
    
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        
        adj[u][v] = v;
        adj[v][u] = u;
    }
    
    for (int u = 1; u < N+1; ++u)
        BFS(u);
    
    int num = 1, min = totalDist[num];
    
    for (int u = 2; u < N+1; ++u)
    {
        if (min > totalDist[u])
        {
            min = totalDist[u];
            num = u;
        }
    }
    
    printf("%d\n", num);
    
    return 0;
}
