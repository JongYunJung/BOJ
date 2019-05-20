// BOJ 10546 - 배부른 마라토너
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<string> participant(n);
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        participant[i] = name;
    }
    
    vector<string> completion(n-1);
    for (int i = 0; i < n-1; i++) {
        string name;
        cin >> name;
        completion[i] = name;
    }
    
    unordered_map<string, int> um;
    for (string name : completion) {
        if (um.find(name) == um.end()) um[name] = 1;
        else um[name]++;
    }
    
    string answer = "";
    for (string name : participant) {
        if (um.find(name) == um.end()) {
            answer = name;
            break;
        } else {
            um[name]--;
            if (um[name] < 0) {
                answer = name;
                break;
            }
        }
    }
    
    cout << answer << '\n';
    return 0;
}
