#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int index1 = 0, index2 = 0, sz = queue1.size();
    long long total1 = 0, total2 = 0;
    
    for (auto q: queue1) total1 += q;
    for (auto q: queue2) total2 += q;
    
    while (total1 != total2 && index1+index2 <= sz+sz+1){

        if (index1 >= sz){
            total1 -= queue2[index1-sz];   
            total2 += queue2[index1-sz];
            index1++;
        }
        else if (index2 >= sz){
            total1 += queue1[index2-sz];   
            total2 -= queue1[index2-sz];
            index2++;
        }
        else if (total1 < total2){
            total1 += queue2[index2];   
            total2 -= queue2[index2];
            index2++;
        }
        else if (total1 > total2) {
            total1 -= queue1[index1];   
            total2 += queue1[index1];
            index1++;
        }
        answer++;
    }
    if (total1 != total2) return -1;
    
    return answer;
}
