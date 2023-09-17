#include <bits/stdc++.h>
using namespace std;
int p1, p2, temp;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long total1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long total2 = accumulate(queue2.begin(), queue2.end(), 0);
    if((total1 + total2) % 2) return -1;
    
    queue<int> q1(deque<int>(queue1.begin(),queue1.end()));
    queue<int> q2(deque<int>(queue2.begin(),queue2.end()));

    while(answer < (q1.size() + q2.size()) * 2){
        if(total1 == total2) // finish
            return answer;
        
        if(total1 > total2){ // pop p1
            //cout << "popped p1\n";
            temp = q1.front();
            q1.pop();
            total1 -= temp;
            total2 += temp;
            q2.push(temp);
        } else { // finish
            //cout << "popped p2\n";
            temp = q2.front();
            q2.pop();
            
            total1 += temp;
            total2 -= temp;
            q1.push(temp);
        }
        answer++;
    }
    return -1;
}
