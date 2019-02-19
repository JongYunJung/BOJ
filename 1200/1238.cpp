// BOJ 1238
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

enum EGraph { eFoward = 0, eReverse = 1, eGraphSize = 2 };
const int MaxVertex = 1001;
const int nINF = 0x7FFFFFFF;

vector<pair<int, int> > graph[eGraphSize][MaxVertex];
vector<int> dist[eGraphSize];

int N, M, X;

void Dijkstra(EGraph eGraph)
{
    dist[eGraph] = vector<int>(N+1, nINF);
    
    dist[eGraph][X] = 0;
    
    priority_queue<pair<int, int> > pq;
    
    pq.push(make_pair(0, X));
    
    while (!pq.empty())
    {
        int curDist = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if (dist[eGraph][here] < curDist)
            continue;
        
        for (size_t i = 0; i < graph[eGraph][here].size(); ++i)
        {
            int there = graph[eGraph][here][i].first;
            int nextDist = curDist + graph[eGraph][here][i].second;
            
            if (dist[eGraph][there] > nextDist)
            {
                dist[eGraph][there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &X);
    
    do
    {
        int s, e, t;
        scanf("%d %d %d", &s, &e, &t);
        
        graph[eFoward][s].push_back(make_pair(e, t));
        graph[eReverse][e].push_back(make_pair(s, t));
        
    } while (--M);
    
    Dijkstra(eFoward);
    Dijkstra(eReverse);
    
    int ret = 0;
    
    for (int u = 1; u <= N; ++u)
        ret = max(ret, dist[eFoward][u] + dist[eReverse][u]);
    
    printf("%d\n", ret);
    
    return 0;
}
