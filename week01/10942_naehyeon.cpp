#include <bits/stdc++.h>
using namespace std;

//Concept referenced by https://cocoon1787.tistory.com/326 ...

int N, M, suyeol[2001], dp[2001][2001];

void set_dp(){
    for(int i = 1; i < N; i++){
        if(suyeol[i] == suyeol[i+1]) dp[i][i+1] = 1;
    }

    ///warning!! i : section length(= end - start), j : start position
    //if (i == odd)  -> between length = even
    //if (i == even) -> between length = odd
    for(int i = 2; i < N; i++){
        // j ~ i + j
        for(int j = 1; i + j <= N; j++){
            if(dp[j + 1][i + j - 1] && suyeol[j] == suyeol[i + j]) {
                dp[j][i + j] = 1;
            }
        }

    }

    //cout << "dp_set finished successfully...\n";
}

void ask(){
    int S, E;
    cin >> M;
    while(M--){
        cin >> S >> E;
        //cout << "dp[" << S << "]" << "[" << E << "] : ";
        cout << dp[S][E] << "\n";
    }
}

void input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> suyeol[i];
        dp[i][i] = 1;
    }
}

int main(){
    //if don't write this line, going to be error
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    input();
    set_dp();
    ask();
}
