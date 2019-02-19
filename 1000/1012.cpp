// BOJ 1012
#include <stdio.h>

using namespace std;

int T, M, N, K, earthwarm;
int map[50][50] = {0};

void DFS(int Y, int X, bool isRoot);

int main()
{
    scanf("%d", &T);    // input T case
    
    do
    {
        scanf("%d %d %d", &M, &N, &K);
        
        for (int i = 0; i < K; ++i)
        {
            int X, Y;
            scanf("%d %d", &X, &Y);
            
            ++map[Y][X];    // map[Y][X] = 1
        }
        
        earthwarm = 0;
        
        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < M; ++x)
            {
                if (map[y][x])
                    DFS(y, x, true);    // DFS
            }
        }
        
        printf("%d\n", earthwarm);
        
    } while (--T);
    
    return 0;
}

void DFS(int Y, int X, bool isRoot)
{
    if (Y < 0 || Y >= N || X < 0 || X >= M)
        return;
    
    if (map[Y][X])
    {
        --map[Y][X];    // map[Y][X] = 0
        
        DFS(Y, X+1, false);    // 우
        DFS(Y+1, X, false); // 하
        DFS(Y, X-1, false); // 좌
        DFS(Y-1, X, false);    // 상
    }
    
    if (isRoot)
        ++earthwarm;
}
