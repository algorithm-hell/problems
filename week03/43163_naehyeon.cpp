#include <bits/stdc++.h>
using namespace std;

vector<string> w_list;

bool isin(vector<string>& words, string w){
    return (find(words.begin(), words.end(), w) != words.end());
}

int solution(string begin, string target, vector<string> words) {
    queue<pair<string, int>> q;
    int answer = 0;
    bool canchange = false;
    q.emplace(begin, 0);
    
    while(!q.empty()){
        string temp, now;
        now = q.front().first;
        answer = q.front().second;
        q.pop();
        
        if(now == target) {
            canchange = true;
            break;
        }
        
        
        for(int i = 0; i < begin.length(); i++){
            temp = now;
            for(char ch = 'a'; ch <= 'z'; ch++){
                temp[i] = ch;
                if(isin(words, temp) && find(w_list.begin(), w_list.end(), temp) == w_list.end()){
                    w_list.push_back(temp);
                    q.emplace(temp, answer+1);
                    //cout << temp << " is in words\n";
                
                }
            }
        }
    }
    if(!canchange){
        answer = 0;
    }
    
    cout << "answer : " << answer << "\n";
    
    
    return answer;
}
