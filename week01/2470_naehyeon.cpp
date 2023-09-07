#include <bits/stdc++.h>
using namespace std;

int N, mixval_abs, mix1, mix2;
vector<int> liquid;

int get_mixval(int pos1, int pos2){
    return abs(liquid[pos1] + liquid[pos2]);
}

void mixliq(){
    int p1, p2, movp1, movp2, mov;
    p1 = 0, p2 = N - 1;
    mix1 = liquid[p1], mix2 = liquid[p2];
    mixval_abs = get_mixval(p1, p2);

    while(1 < p2 - p1){

        movp1 = get_mixval(p1 + 1, p2);
        movp2 = get_mixval(p1, p2 - 1);

        if( movp1 <= movp2 ){
            p1++;
            mov = movp1;
            //cout << "moved p1...\n";

        } else {
            p2--;
            mov = movp2;
            //cout << "moved p2...\n";

        }

        if(mov < mixval_abs){
            mix1 = liquid[p1], mix2 = liquid[p2];
            mixval_abs = mov;
        }

    }

    cout << mix1 << " " << mix2 << "\n";
}

void input() {
    cin >> N;
    liquid.resize(N);
    for(int& slot : liquid)
        cin >> slot;
    sort(liquid.begin(), liquid.end());
}

int main() {
    input();
    mixliq();
}
