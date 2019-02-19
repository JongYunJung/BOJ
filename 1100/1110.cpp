// BOJ 1110
#include <iostream>
using namespace std;

int main()
{
    int n;
    int arrData[2];
    int resultData[2];
    int sum = 0, resValue = 0, cycleLength = 0;
    
    cin >> n;
    
    arrData[0] = n / 10;
    arrData[1] = n % 10;
    
    sum = arrData[0] + arrData[1];
    
    do
    {
        resultData[0] = sum / 10;
        resultData[1] = sum % 10;
        
        arrData[0] = arrData[1];
        arrData[1] = resultData[1];
        
        sum = arrData[0] + arrData[1];
        resValue = (arrData[0] * 10) + arrData[1];
        ++cycleLength;
    } while (n != resValue);
    
    cout << cycleLength << endl;
    
    return 0;
}

