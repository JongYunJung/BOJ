// BOJ 1074
#include <iostream>
#include <math.h>

using namespace std;

int res, n, r, c;

// 분할 정복, 재귀 호출
// 1. r,c의 값이 분할한 영역에 있는지 판단한다. (초기에는 그냥 영역)
// 2. 있다면, 4개의 영역으로 분할 하고 재귀 호출을 한다. ( 1번으로.. )
// 3. 없다면, res 값에 사각형 넓이 값을 더한다. (없으므로 Pass 하는 과정)
// 4. 찾을 때 까지 재귀 호출

void Z_Recursive(int nY, int nX, int nSize)
{
    if (nY == r && nX == c)
    {
        cout << res << endl;
        
        return;
    }
    
    if (r >= nY && r < (nY + nSize) && c >= nX && c < (nX + nSize))
    {
        int nHalfOfSize = nSize / 2;
        
        Z_Recursive(nY, nX, nHalfOfSize);
        Z_Recursive(nY, nX + nHalfOfSize, nHalfOfSize);
        Z_Recursive(nY + nHalfOfSize, nX, nHalfOfSize);
        Z_Recursive(nY + nHalfOfSize, nX + nHalfOfSize, nHalfOfSize);
    }
    else
    {
        res += nSize * nSize;
    }
}

// main
int main()
{
    cin >> n >> r >> c;
    
    res = 0;
    
    Z_Recursive(0, 0, (int)(pow(2, n)));
    
    return 0;
}
