#include <bits/stdc++.h>

using namespace std;
int jobs[10001][2];

int main() {
    int N, answer = 0;
    cin >> N;
    for (int i=0; i<N; i++){
        int mtime, num, inp;
        cin >> mtime >> num;
        int max_job = 0;
        for (int j=0; j<num; j++){
            cin >> inp;
            max_job = max(max_job, jobs[inp-1][1]);
        }
        jobs[i][0] = max_job;
        jobs[i][1] = jobs[i][0] + mtime;
        answer = max(answer, jobs[i][1]);
    }
    cout << answer;


    return 0;
}
