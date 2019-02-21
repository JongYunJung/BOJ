// BOJ 1325 - 효율적인 해킹
#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> graph[10001];
vector<int> discov = vector<int>(10001, 0);
vector<int> dist = vector<int>(10001, 0);

int N, M;

int main()
{
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        
        graph[b].push_back(a);
    }
    
    int maxDist = 0;
    
    for (int u = 1; u <= N; ++u)
    {
        int cnt = 0;
        
        int rootNum = u;
        
        if (discov[u] != rootNum)
        {
            discov[u] = rootNum;
            
            queue<int> q;
            
            q.push(u);
            
            while (!q.empty())
            {
                int current = q.front();
                q.pop();
                
                for (int i = 0; i < (int)graph[current].size(); ++i)
                {
                    int next = graph[current][i];
                    
                    if (discov[next] != rootNum)
                    {
                        discov[next] = rootNum;
                        
                        q.push(next);
                    }
                }
                
                ++cnt;
            }
            
            dist[u] = cnt;
            
            maxDist = max(maxDist, dist[u]);
        }
    }
    
    for (int u = 1; u <= N; ++u)
    {
        if (maxDist == dist[u])
            printf("%d ", u);
    }
    
    printf("\n");
    
    return 0;
}

