#include <bits/stdc++.h>
using namespace std;
vector<int> sales, answer(2), now(2);
int emo_num;

int get_sale(int price, int percent){
    return (price / 10) * (10 - percent);
}

void percent_case(int count, vector<vector<int>>& users, vector<int>& emoticons) {
    now[0] = 0;
    now[1] = 0;
	if (count == emo_num) {
        //////////////
        for(int i = 0; i < users.size(); i++){
            int price = 0;
            
            for(int j = 0; j < emo_num; j++){
                if(users[i][0] <= sales[j] * 10){ //yes perchase

                    price += get_sale(emoticons[j], sales[j]);
                    //cout << "sale's price of "<< emoticons[j] << ", " << get_sale(emoticons[j], sales[j]) << " purchased... total price : " << price << "\n";

                    if(users[i][1] <= price){
                        price = 0;
                        now[0]++;
                        break;
                    }

                }


            }
            //cout << i << "th user  : " << now[0] << ",  " << now[1] << "\n";
            now[1] += price;
            
        }
        if(now[0] > answer[0] || now[0] == answer[0] && now[1] > answer[1]){
            answer = now;
        }
        //////
        
	} else {
		for (int i = 1; i <= 4; i++) { // 10, 20, 30, 40
				sales[count] = i;
				percent_case(count + 1, users, emoticons);
		}
	}
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    emo_num = emoticons.size();
    sales.resize(emo_num);
    ////////////////
    percent_case(0, users, emoticons);
    ////////////////
    
    cout << "result : " << answer[0] << ", " << answer[1] << "\n";
    return answer;
}
