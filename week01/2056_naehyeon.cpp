#include <bits/stdc++.h>
using namespace std;

int N, dp_time[10001]; // n's job finished time
bool visited[10001];
vector<int> infor[2]; // time, indegree
vector<int> node[10001];

void job(){
    queue<int> able_job;

    for(int i = 1; i <= N; i++){ // no pre-job pushing
        if(infor[1][i] == 0){
            visited[i] = true;
            able_job.push(i);
        }
    }

    while(!able_job.empty()) {
        int now = able_job.front();
        able_job.pop();
        dp_time[now] += infor[0][now];

        for(auto & next : node[now]){
            infor[1][next]--;
            dp_time[next] = max(dp_time[next], dp_time[now]);
            if(!visited[next] && infor[1][next] == 0){ // can perform
                able_job.push(next);
                visited[next] = true;
            }
        }

    }

    cout << *max_element(dp_time, dp_time + N + 1) << "\n";
}

void input(){
    int tt, ind, pre_job;
    cin >> N;
    infor[0].resize(N + 1);
    infor[1].resize(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> tt >> ind;
        infor[0][i] = tt;
        infor[1][i] = ind;
        while(ind-- > 0){
            cin >> pre_job;
            node[pre_job].push_back(i);
        }
    }
}

int main() {
    input();
    job();
}
