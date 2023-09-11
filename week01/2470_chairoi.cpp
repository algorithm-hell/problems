#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define INF 2000000000
// 가능한 합의 최댓값 + 1

using namespace std;

vector<int> minAddition(2);
// minAddition[0] = 더 작은 값
// minAddition[1] = 더 큰 값

int main() {
    int N;
    cin >> N;
    vector<int> input(N);

    for (int i = 0; i < N; ++i) cin >> input[i];

    sort(input.begin(), input.end());

    int smaller = 0;
    int larger = N - 1;
    int min = INF;

    while (smaller < larger) {
        int sum = input[smaller] + input[larger];

        if (min > abs(sum)) {
            min = abs(sum);
            minAddition[0] = input[smaller];
            minAddition[1] = input[larger]; 

            if (sum == 0)
                break;
        }

        if (sum < 0) 
            smaller++;
        else 
            larger--;
    }

    cout << minAddition[0] << " " << minAddition[1];
}
