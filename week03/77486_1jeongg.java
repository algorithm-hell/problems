#include <bits/stdc++.h>

using namespace std;


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, string> ddg;
    map<string, int> money;
    
    int sz = enroll.size();
    
    for (int i=0; i<sz; i++){
        ddg[enroll[i]] = referral[i];
    }
    int sz2 = seller.size();
    for (int i=0; i<sz2; i++){
        string s = seller[i];
        int a = amount[i] * 100;
        while (s != ""){
            money[s] += a - a/10;
            a /= 10;
            s = ddg[s];
            if (a <= 0) break;
        }   
    }
    for (int i=0; i<sz; i++){
        answer.push_back(money[enroll[i]]);
    }
    
    return answer;
}
