#include <bits/stdc++.h>
using namespace std;
int visited[100];
int answer = 1e9;

bool isValid(string a, string b){
    int tmp = 0;
    for (int i=0; i<a.size(); i++){
        if (a[i] != b[i]) tmp++;
        if (tmp > 1) return false;
    }
    return true;
}
void dfs(string begin, string target, vector<string> words, int depth){
    if (depth > answer) return;
    if (begin == target) {
        answer = depth;
        return;
    }
    
    for (int i=0; i<words.size(); i++){
        if (isValid(words[i], begin) && !visited[i]){
            visited[i] = true;
            dfs(words[i], target, words, depth+1);
            visited[i] = false;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words,0);
    if (answer == 1e9) return 0;
    return answer;
}
