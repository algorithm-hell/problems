#include <bits/stdc++.h>

using namespace std;

int N, M, s, e;
int nums[2001];
int palindrome[2001][2001] = {0,};

int main() {

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++){
        cin >> nums[i];
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (i+j >= N) continue;
            if (i == 0) palindrome[j][j] = 1;
            else if (nums[j+i] == nums[j]){
                if (j+1 < j+i-1 && palindrome[j+1][j+i-1] == 0) palindrome[j][j+i] = 0;
                else palindrome[j][j+i] = 1;
            }
            else palindrome[j][j+i] = 0;
        }
    }
    cin >> M;
    for (int i=0; i<M; i++){
        cin >> s >> e;
        cout << palindrome[s-1][e-1] << "\n";
    }

    return 0;
}
