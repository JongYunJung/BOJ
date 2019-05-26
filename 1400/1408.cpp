// BOJ 1408 - 24
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string time1;
    cin >> time1;
    
    string time2;
    cin >> time2;
    
    int currentTime = 0;
    currentTime += stoi(time1.substr(0, 2)) * 3600;
    currentTime += stoi(time1.substr(3, 2)) * 60;
    currentTime += stoi(time1.substr(6, 2));
    
    int startTime = 0;
    startTime += stoi(time2.substr(0, 2)) * 3600;
    startTime += stoi(time2.substr(3, 2)) * 60;
    startTime += stoi(time2.substr(6, 2));
    
    if (currentTime > startTime) startTime += 24 * 3600;
    
    int remainingTime = startTime - currentTime;
    
    string answer = "";
    int hour = remainingTime / 3600;
    if (hour < 10) answer += "0";
    answer += to_string(hour) + ":";
    
    int min = (remainingTime % 3600) / 60;
    if (min < 10) answer += "0";
    answer += to_string(min) + ":";
    
    int sec = (remainingTime % 3600) % 60;
    if (sec < 10) answer += "0";
    answer += to_string(sec);
    
    cout << answer << '\n';
    return 0;
}
