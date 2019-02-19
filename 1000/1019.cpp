// BOJ 1019
#include <iostream>

using namespace std;

long long llPageCount[10] = {0};

void calculate(long long llN, long long llTen)
{
    while(llN > 0)
    {
        llPageCount[llN % 10] += llTen;
        llN /= 10;
    }
}

void BookPage_Recursive(long long llStart, long long llEnd, long long llTen)
{
    // Start 부분의 1의 자리를 0으로 만들어 주는 과정
    // 그 과정에서 범위 안에 없는 일의 자리도 Count 측정 됨
    while (llStart % 10 != 0 && llStart <= llEnd)
    {
        calculate(llStart, llTen);
        llStart++;
    }
    
    if (llStart > llEnd)
        return;
    
    // End 부분의 1의자리를 9로 만들어 주는 과정
    // 그 과정에서 범위 안에 없는 일의 자리도 Count 됨
    while (llEnd % 10 != 9 && llStart <= llEnd)
    {
        calculate(llEnd, llTen);
        llEnd--;
    }
    
    // 자릿수의 0 ~ 9 Count
    long long llCount = (llEnd / 10) - (llStart / 10) + 1;
    
    // 자릿수의 Count 저장 ( 일의 자리, 십의 자리 ~ 에 따른 llTen 곱하기 )
    for (int i=0; i<10; ++i)
        llPageCount[i] += llCount * llTen;
    
    BookPage_Recursive((llStart / 10), (llEnd / 10), (llTen * 10LL));
}

int main()
{
    long long llN;
    
    cin >> llN;
    
    BookPage_Recursive(1, llN, 1);
    
    for (int i=0; i<10; ++i)
        cout << llPageCount[i] << " ";
    
    cout << "\n";
    
    return 0;
}
