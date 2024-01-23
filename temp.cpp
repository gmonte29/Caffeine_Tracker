#include <vector>
#include <utility>
#include <stack>
#include <string>
#include <iostream>
using namespace std;




void exclusiveTime(int n, vector<string>& logs) {
    vector<int> ans(n);
    stack<pair<int,int>> cur;
    int prevTime = 0;
    for (auto& s : logs){
        int num = stoi(s.substr(0, s.find(':')));
        int time = stoi(s.substr(s.rfind(':') + 1));
        if (s.find('e') != -1){
            ans[num] += time - prevTime + 1;
            cur.pop();
            prevTime = time + 1;
        }
        else{
            if (!cur.empty()) ans[cur.top().first] += time - prevTime ;
            cur.push({num, time});
            prevTime = time;
        }
    }
    for(int i : ans) cout << i << " \n";
}


int main(){
    vector<string> v{"1:start:2","0:start:0","1:end:5","0:end:6"};
    
    exclusiveTime(2, v);
    return 0;
}