#include <bits/stdc++.h>
using namespace std;
vector<long long> timestamp(360000);

int timetosec(string play_time){
    vector<int> hms;
    for(int i = 0; i < play_time.length(); i += 3){
        int ship = play_time[i] - '0';
        int ill  = play_time[i + 1] - '0';
        hms.push_back(ship * 10 + ill);
    }
    return hms[0] * 3600 + hms[1] * 60 + hms[2];
}

string sectotime(int play_time){
    string hms[3];
    hms[0] = to_string(play_time / 3600);
    hms[1] = to_string((play_time % 3600) / 60);
    hms[2] = to_string(play_time % 60);
    
    for(int i = 0; i < 3; i++){
        if(hms[i].length() == 1){
            hms[i] = "0" + hms[i];
        }
    }
    return hms[0] + ":" + hms[1] + ":" + hms[2];
}

string solution(string play_time, string adv_time, vector<string> logs) {
    long long best_interesting, people_attention;
    int total_length, adv_length;
    best_interesting = 0;
    total_length = timetosec(play_time);
    adv_length   = timetosec(adv_time);
    
    for(auto & tlog : logs){
        string st1, st2;
        st1 = tlog.substr(0, 8);
        st2 = tlog.substr(9, 8);
        //cout << st1 << " " << st2 << "\n";
        //int t1, t2;
        //t1 = timetosec(st1), t2 = timetosec(st2);
        timestamp[timetosec(st1)]++;
        timestamp[timetosec(st2)]--;
    }
    
    for(int i = 1; i <= total_length; i++){
        timestamp[i] += timestamp[i - 1];
    }
    
    for(int i = 1; i <= total_length; i++){
        timestamp[i] += timestamp[i - 1];
    }
    
    people_attention = timestamp[adv_length - 1];
    for(int i = adv_length - 1; i <= total_length; i++){
        long long temp_attention = timestamp[i] - timestamp[i - adv_length];
        if(people_attention < temp_attention){
            people_attention = temp_attention;
            best_interesting = i - adv_length + 1;
        }
            
    }
    
    string answer = sectotime(best_interesting);
    return answer;
}
