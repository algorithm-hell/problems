#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> mountain[50001];
int dist[50001];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    int diff[50001] = {0, };
    for (auto g: gates) diff[g] = 1;
    for (auto s: summits) diff[s] = 2;
    
    for (auto path: paths){
        int i = path[0], j = path[1], w = path[2];
        if (diff[i] == 1 || diff[j] == 2)
            mountain[i].push_back({j,w});
        else if (diff[i] == 2 || diff[j] == 1)
            mountain[j].push_back({i,w});
        else {
            mountain[i].push_back({j,w});
            mountain[j].push_back({i,w});
        }
    }
    
    sort(summits.begin(), summits.end());
    fill(dist, dist+50001, 1e9);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    for (auto g: gates){
        pq.push({0, g});
        dist[g] = 0;
    }
  
    while (!pq.empty()){
        auto [x, y] = pq.top();
        pq.pop();
        if (dist[y] < x) continue;
        for (auto m: mountain[y]){
            int tx = m.first, ty = m.second;
            if (dist[tx] > max(x, ty)) {
                dist[tx] = max(x, ty);
                pq.push({dist[tx], tx});
            }
        }
    }
    int min_intensity = 1e9, min_course = 1e9;
    for (auto s: summits){
        cout << s << " " << dist[s] << endl;
        if (dist[s] == min_intensity){
            min_course = min(min_course, s);
        }
        if (dist[s] < min_intensity){
            min_intensity = dist[s];
            min_course = s;
        }
    }
    answer.push_back(min_course);
    answer.push_back(min_intensity);
    
    return answer;
}
