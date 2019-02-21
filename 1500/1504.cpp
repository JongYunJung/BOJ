// BOJ 1504 - 특정한 최단 경로
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

enum { eMaxV = 801, eINF = 800001 };

vector<pair<int, int> > graph[eMaxV];

inline int GetMin(int lv, int rv)    { return (lv > rv) ? rv : lv; }

vector<int> Dijkstra(int start, int V)
{
    vector<int> dist(V, eINF);
    
    dist[start] = 0;
    
    priority_queue<pair<int, int> > pq;
    
    pq.push(make_pair(0, start));
    
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if (dist[here] < cost)
            continue;
        
        for (size_t i = 0; i < graph[here].size(); ++i)
        {
            int there = graph[here][i].first;
            int thereCost = cost + graph[here][i].second;
            
            if (dist[there] > thereCost)
            {
                dist[there] = thereCost;
                pq.push(make_pair(-thereCost, there));
            }
        }
    }
    
    return dist;
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);
    
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    
    int ret1 = 0, ret2 = 0;
    
    vector<int> dist;
    dist = Dijkstra(1, V+1);
    ret1 += dist[v1];    // 1 -> v1
    ret2 += dist[v2];    // 1 -> v2
    
    dist = Dijkstra(v1, V+1);
    ret1 += dist[v2];    // v1 -> v2
    ret2 += dist[V];    // v1 -> N
    
    dist = Dijkstra(v2, V+1);
    ret1 += dist[V];    // v2 -> N
    ret2 += dist[v1];    // v2 -> v1
    
    ret1 = GetMin(ret1, ret2);
    
    printf("%d\n", (ret1 > eINF) ? -1 : ret1);
    
    return 0;
}
