#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_map<string, int> shopping;
    set<string> kind(gems.begin(), gems.end());
    vector<int> answer(2);
    int i, start, end, minlen = 100001;
    start = end = 0;
    
    if(kind.size() == 1){
        return {1, 1};
    } 

    while(true){
        
        //move end
        for(i = end; i < gems.size(); i++){
            shopping[gems[i]]++;
            if(shopping.size() == kind.size()){
                end = i;
                break;
            }
        }
        
        if(i == gems.size()){
            break;
        }
        
        //update start
        for(int i = start; i < gems.size(); i++){
            if(shopping[gems[i]] == 1){
                start = i;
                break;
            }
            shopping[gems[i]]--;
            
            cout << "start : " << start << ", end : " << end << "\n";
            cout << "i : " << i << "\n";
        }
        
        if(end - start < minlen){
            minlen = (end - start);
            answer[0] = start + 1;
            answer[1] = end + 1;
            //cout << "answer[0] = " << answer[0] << ", answer[1] = " << answer[1] << "\n";
            
        }
        
        shopping.erase(gems[start]);
        start++;
        end++;
        
    }
    //cout << "answer[0] = " << answer[0] << ", answer[1] = " << answer[1] << "\n";
    
    return answer;
}
