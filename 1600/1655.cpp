// BOJ 1655 - 가운데를 말해요
/*
 1. 최대 힙의 크기는 최소 힙의 크기와 같거나 하나 더 크다.
 2. 최대 힙의 최대 원소는 최소 합의 최소 원소보다 작거나 같다.
 이 때 알고리즘이 맞지 않다면.. 최대 힙, 최소 힙의 가장 위의 값을 SWAP 해준다.
 */
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, less<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    while (n--) {
        int value;
        cin >> value;
        
        if (maxHeap.empty())
            maxHeap.push(value);
        else if (maxHeap.size() == minHeap.size())
            maxHeap.push(value);
        else
            minHeap.push(value);
        
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int maxHeapValue = maxHeap.top();
            int minHeapValue = minHeap.top();
            
            maxHeap.pop();
            minHeap.pop();
            
            maxHeap.push(minHeapValue);
            minHeap.push(maxHeapValue);
        }
        
        cout << maxHeap.top() << '\n';
    }
    
    return 0;
}
