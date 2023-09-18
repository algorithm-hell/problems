#include <iostream>
#include <algorithm>

using namespace std;

int ifPalindrom[2001][2001];
int num[2001];
int N, M;
int S, E;

int main(void) {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i < N + 1; i++) {
        cin >> num[i];

        ifPalindrom[i][i] = 1;
        if (i != 1 && num[i - 1] == num[i]) ifPalindrom[i - 1][i] = 1;
        // 한 자리 수와 두 자리가 같은 경우의 ifPalindrom 값 저장
    }

    for (int i = 2; i < N; i++) {
        for (int j = 1; i + j < N + 1; j++) {
            if (num[j] == num[i + j] && ifPalindrom[j + 1][i + j - 1] == 1) {
                ifPalindrom[j][i + j] = 1;
            }
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> S >> E;
        cout << ifPalindrom[S][E] << "\n";
    }

    return 0;
}
