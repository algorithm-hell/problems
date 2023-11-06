#include <string>
#include <vector>

using namespace std;

int INTMAX = 20000000;

class TaxiMap {
public:
    TaxiMap(int n) {
        costs = vector<vector<int>>(
            n+1, vector<int>(
                n+1, INTMAX
            )
        );

        for (int i=1; i<=n; i++) {
            costs[i][i]=0;
        }
    }

    // 두 지점 간 택시 비용을 설정한다.
    void setCost(int from, int to, int cost) {
        costs[from][to] = cost;
        costs[to][from] = cost;
    }

    // Floyd-Warshall을 통해 모든 지점 간 최소비용을 구한다.
    void calculate() {
        for (int k=1; k<=size(); k++) {
            for (int r=1; r<=size(); r++) {
                for (int c=1; c<=size(); c++) {
                    int stopOver = costs[r][k] + costs[k][c];
                    int direct = costs[r][c];

                    if (stopOver < direct) costs[r][c] = stopOver;
                }
            }
        }
    }

    int getCost(int from, int to) { return costs[from][to]; }

private:
    int size() { return costs.size()-1; }

    vector<vector<int>> costs;
};

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    TaxiMap map(n);
    
    for (auto fare : fares) {
        map.setCost(fare[0], fare[1], fare[2]);
    }
    map.calculate();

    int optimalCost = INTMAX;
    for (int k=1; k<=n; k++) {
        optimalCost = min(
            optimalCost, 
            map.getCost(s, k) + map.getCost(k, a) + map.getCost(k, b) 
        );
    }

    return optimalCost;
}