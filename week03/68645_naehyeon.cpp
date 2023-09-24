#include <bits/stdc++.h>
#define hwakin() cout << "x : " << x << ", y : " << y << " now : " << now-1 << "\n";
using namespace std;


vector<int> solution(int n) {
    vector<vector<int>> snail(n);
    for(int i = 0; i < n; i++)
        snail[i].resize(i+1);
    
    int now, x, y;
    now = 1, x = -1, y = 0;
    //////////////
    for(int c = n; 0 < c; c -= 3){
        for(int i = 0; i < c; i++){
            snail[++x][y] = now++;
            //cout << "case-i / ";
            //hwakin();
        }
        for(int j = 0; j < c-1; j++){
            snail[x][++y] = now++;
            //cout << "case-j / ";
            //hwakin();
        }
        for(int k = 0; k < c-2; k++){
            snail[--x][--y] = now++;
            //cout << "case-k / ";
            //hwakin();
        
    }
    
    //////////////
    
    vector<int> answer;
    for(auto &a : snail){
        for(auto &b : a){
            //cout << b << " ";
            answer.push_back(b);
        }
        //cout << "\n";
    }
    
    
    return answer;
}
