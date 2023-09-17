#include <bits/stdc++.h>

using namespace std;
int answer_mem = 0, answer_price = 0;

void dfs(vector<vector<int>> &users, vector<int> &emoticons, vector<int> vec, int sz){
    if (vec.size() == sz) {
        int plus_member = 0, total_price = 0;
        for (auto user: users){
            int price = 0;
            int user_rate = user[0], user_price = user[1];
            for (int i=0; i<emoticons.size(); i++){
                if (user_rate <= vec[i]){
                    price += emoticons[i] * (100-vec[i]) / 100;
                }
            }
            if (price >= user_price) plus_member ++;
            else total_price += price;
        }
        
        if (answer_mem == plus_member){
            answer_price = max(answer_price, total_price);
        }
        if (answer_mem < plus_member){
            answer_mem = plus_member;
            answer_price = total_price;
        }
        return;
    }
    for (int i=1; i<=4; i++){
        vec.push_back(i*10);
        dfs(users, emoticons, vec, sz);
        vec.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int> v;
    dfs(users, emoticons, v, emoticons.size());
    
    answer.push_back(answer_mem);
    answer.push_back(answer_price);
    
    return answer;
}
