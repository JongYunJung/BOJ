// BOJ 1525 - 퍼즐
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

enum { eSize = 3 };

map<int, int> movecount;

const int dY[4] = {0, 1, 0, -1};
const int dX[4] = {1, 0, -1, 0};

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    
    movecount[start] = 0;
    
    while (!q.empty())
    {
        int here = q.front();
        string strHere = to_string((long long)here);
        q.pop();
        
        if (here == 123456789)
            break;
        
        int i = strHere.find('9');
        int cY = i / 3;
        int cX = i % 3;
        
        for (int d = 0; d < 4; ++d)
        {
            int nY = cY + dY[d];
            int nX = cX + dX[d];
            
            if (nY < 0 || nY >= eSize || nX < 0 || nX >= eSize)
                continue;
            
            string strThere = strHere;
            
            swap(strThere[cY * 3 + cX], strThere[nY * 3 + nX]);
            
            int there = stoi(strThere);
            
            if (movecount.count(there) == 0)
            {
                movecount[there] = movecount[here] + 1;
                q.push(there);
            }
        }
    }
}

int main()
{
    int start = 0;
    
    for (int y = 0; y < eSize; ++y)
    {
        for (int x = 0; x < eSize; ++x)
        {
            int num;
            scanf("%d", &num);
            
            if (num == 0)
                num = 9;
            
            start = start * 10 + num;
        }
    }
    
    BFS(start);
    
    printf("%d\n", (movecount.count(123456789) == 0) ? -1 : movecount[123456789]);
    
    return 0;
}
