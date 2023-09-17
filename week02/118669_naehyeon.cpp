#include <bits/stdc++.h>
using namespace std;

//referenced by https://blogshine.tistory.com/564...

int intensity[50001];
////////
bool visited[50001];
vector<pair<int, int>> edge[50001]; //[from] -> {intensity, to} 


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    
    vector<int> answer = {-1, -1}; // top num, intensity
    
    for(auto info : paths){
        edge[info[0]].emplace_back(info[2], info[1]);
        edge[info[1]].emplace_back(info[2], info[0]);
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    for(auto src : gates){
        q.emplace(0, src); //intensify, node
        visited[src] = true;
    }
    
    while(!q.empty()){
        int now, inten;
        now = q.top().second;
        inten = q.top().first;
        q.pop();
        
        if(answer[0] != -1 && answer[1] < inten) continue; //cut case
        
        if(find(summits.begin(), summits.end(), now) != summits.end()){ 
            //cout << now << " is summit!\n";
            if(answer[1] == -1 || inten < answer[1] 
						|| (inten == answer[1] && now < answer[0])){
                answer[0] = now;
                answer[1] = inten;
            }
            continue;
        }
        
        //dijkstra algorithm part
        
        for(auto next : edge[now]){
            int next_node, ninten;
            next_node = next.second;
            ninten = next.first;
            ninten = max(inten, ninten);
            
            if(!visited[next_node] || ninten < intensity[next_node]){
                visited[next_node] = true;
                intensity[next_node] = ninten;
                q.emplace(ninten, next_node);
            }
            
        }
        
    }
    
    ////////////

    
    return answer;
}
