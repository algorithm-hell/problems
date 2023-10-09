#include <bits/stdc++.h>

using namespace std;
map<string, int> mymap;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> gems_set(gems.begin(), gems.end());
    int set_size = gems_set.size(); // 보석 종류 개수

    map<int, int> m; // 보석의 index 기록 (ordered_map)
    
    int index = 1, total = 0;
    int min_val = 0, max_val = 1e9;
    
    for (auto gem: gems){
        m[index] = index; // 현재 보석의 index 저장

        if (mymap[gem] == 0) total++; // 새로 추가된 보석일 경우
        else m.erase(mymap[gem]); // 이전에 존재하던 보석일 경우 (old 보석 index 지움)
        
        if (total == set_size) { // 보석 다 모음
            int a = m.begin()->first, b = m.rbegin()->first; // 시작 index, 끝 index
            if (max_val - min_val > b-a){
                max_val = b;
                min_val = a;
            }
            if (max_val - min_val == b-a && min_val > a){
                max_val = b;
                min_val = a;
            }
        }
        mymap[gem] = index; // 보석 이름 <- 현재 index 저장
        index++;
    }

    answer.push_back(min_val);
    answer.push_back(max_val);
    return answer;
}
