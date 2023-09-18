#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> allPaths[50001]; // [0] == node, [1] == intensity
vector<int> dist(50001, 10000001);
vector<bool> ifSummit(50001, false);

vector<int> daj(vector<int> gates, vector<int> summits) {
    priority_queue<vector<int>> queue; // [0] == intensity, [1] = node
    vector<int> res = {50001, 10000001};

    for (int i : gates) {
        queue.push({0, i});
        dist[i] = 0;
    }

    for (int i : summits) {
        ifSummit[i] = true;
    }

    while (!queue.empty()) {
        vector<int> top = queue.top();
        queue.pop();

        for (vector<int> i : allPaths[top[1]]) {
            if (max(dist[top[1]], i[1]) < dist[i[0]]) {
                dist[i[0]] = max(dist[top[1]], i[1]);
                if (ifSummit[top[1]] == false) {
                    queue.push({dist[i[0]], i[0]});
                }
                if (ifSummit[i[0]] == true)
                    if (dist[i[0]] < res[1] || (dist[i[0]] == res[1] && i[0] < res[0]))
                        res = {i[0], dist[i[0]]};
            }
        }
    }

    return res;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for (vector<int> i : paths) {
        allPaths[i[0]].push_back({i[1], i[2]});
        allPaths[i[1]].push_back({i[0], i[2]});
    }

    vector<int> answer = daj(gates, summits);
    return answer;
}
