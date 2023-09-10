#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, inp;
    vector<int> solutions;

    cin >> N;
    for (int i=0; i<N; i++){
        cin >> inp;
        solutions.push_back(inp);
    }
    sort(solutions.begin(), solutions.end());

    int answer = 1e9+1e9, x=0, y=0;
    int start_index = 0, end_index = N-1;
    while (start_index < end_index){
        int a = solutions[start_index], b = solutions[end_index];
        if (abs(answer) > abs(a+b)){
            answer = a+b;
            x = a, y = b;
        }

        if (abs(a) < abs(b)) end_index--;
        else start_index++;
    }
    cout << x << " " << y << endl;


    return 0;
}
