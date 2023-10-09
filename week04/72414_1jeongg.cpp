#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll ad[361111];

ll str_to_long(string s){
    string a = "";
    ll hour = stoi(a+s[0]+s[1]);
    ll min = stoi(a+s[3]+s[4]);
    ll sec = stoi(a+s[6]+s[7]);
    return hour*60*60 + min*60 + sec;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    ll time = str_to_long(play_time);
    for (auto log: logs){
        ll a = str_to_long(log.substr(0,8));
        ll b = str_to_long(log.substr(9,17));
        ad[a]++; ad[b]--;
    }
    for (ll i=1; i<time; i++){
        ad[i] += ad[i-1];
    }
    for (ll i=1; i<time; i++){
        ad[i] += ad[i-1];
    }
    ll ad_time = str_to_long(adv_time);
    if (ad_time == 0) return "00:00:00";
    
    ll total = ad[ad_time-1];
    ll ans = 0;
    for (ll i=ad_time; i<time; i++){
        if (total < ad[i] - ad[i-ad_time]){
            total = ad[i] - ad[i-ad_time];
            ans = i - ad_time + 1;
        }
    }
    ll hour = ans/3600;
    ll min  = (ans-hour*3600)/60;
    ll sec = ans%60;
    
    answer += (hour <= 9) ? '0'+to_string(hour)+':' : to_string(hour)+':';
    answer += (min  <= 9) ? '0'+to_string(min)+':'  : to_string(min)+':';
    answer += (sec  <= 9) ? '0'+to_string(sec)      : to_string(sec);
    
    return answer;
}
