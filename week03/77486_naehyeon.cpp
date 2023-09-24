#include <bits/stdc++.h>
using namespace std;

bool visited[10002];
map<string, int> name_to_index;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size());
    int index, price, ten_per, parent_index;
    string parent = "";
    
    for(int i = 0; i < enroll.size(); i++){
        name_to_index[enroll[i]] = i; // 조직원의 이름으로 인덱스값을 찾기위한 밑작업
    }
    
    for(int i = 0; i < seller.size(); i++){
        
        index = name_to_index[seller[i]]; // index : seller[i]의 인덱스값
        price = amount[i] * 100; // 칫솔 수익
        
    }

    while(enroll[index] != "-" && price != 0){
        
        ten_per = price / 10;
        parent = referral[index];
        answer[index] += (price - ten_per);
        
        if(parent == "-") break;
        
        parent_index = name_to_index[parent];
        price = ten_per;
        index = parent_index;
    }
    
    return answer;
}
