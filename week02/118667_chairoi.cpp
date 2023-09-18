#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {

    long long sum = accumulate(queue1.begin(), queue1.end(), 0) + accumulate(queue2.begin(), queue2.end(), 0);

    if (sum % 2 == 1) return -1;
		long long goal = sum / 2;
    if (accumulate(queue1.begin(), queue1.end(), 0) == goal) return 0;

    long long answer = 0;
    long long size = queue1.size();

    int start = 0; int end = size;
    vector<int> queue = queue1;
    queue.insert(queue.end(), queue2.begin(), queue2.end());

    long long partSum1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long partSum2 = accumulate(queue2.begin(), queue2.end(), 0);
    
    while (answer < size * 4) {
        if (partSum1 == partSum2) {
            return answer;
        }
        else if (partSum1 < partSum2) {
            partSum1 += queue[end % (size * 2)];
            partSum2 -= queue[end % (size * 2)];
            end++;
        }
        else {
            partSum1 -= queue[start % (size * 2)];
            partSum2 += queue[start % (size * 2)];
            start++;
        }
        answer++;
    }

    return -1;
}
