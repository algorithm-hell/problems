#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[1001][1001] = {0, };

    int index = 0, x = 0, y = 0, num = 1;
    for (int i=n; i>0; i--){
        for (int j=0; j<i; j++){
            arr[x][y] = num;
            if (index%3 == 0) x++; 
            if (index%3 == 1) y++;
            if (index%3 == 2){ x--; y--; }
            num++;
        }
        if (index%3 == 0) {x--; y++;}
        if (index%3 == 1) {x--; y-=2;}
        if (index%3 == 2) {x+=2; y++;}
        
        index++;
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (arr[i][j]) 
                answer.push_back(arr[i][j]);
        }
    }
    
    
    return answer;
}
