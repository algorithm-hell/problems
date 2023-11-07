#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> split(string s, string delim) {
    vector<string> result;
    string token;
    
    int pos=0;
    while (pos = s.find(delim), pos != string::npos) {
        token = s.substr(0, pos);
        result.push_back(token);
        
        s.erase(0, pos+delim.length());
    }
    result.push_back(s);
    
    return result;
}

enum Command { ENTER, LEAVE, CHANGE, INVALID };

struct Event {
    string uid;
    Command command;
};

class ChatRoom {
public:
    ChatRoom() {}
    
    void parse(string record) {
        vector<string> splitted = split(record, " ");
        
        Command command = parseCommand(splitted[0]);
        string uid = splitted[1];
        
        if (command == ENTER || command == CHANGE) {
            string name = splitted[2];
            users[uid] = name;
        }
        
        events.push_back({uid, command});
    }
    
    vector<string> getLogs() {
        vector<string> logs;
        
        for (Event& event: events) {
            string name = users[event.uid];
            string log;
            
            if (event.command == CHANGE) continue;
            if (event.command == ENTER) log = name + "님이 들어왔습니다.";
            if (event.command == LEAVE) log = name + "님이 나갔습니다.";
            logs.push_back(log);
        }
        
        return logs;
    }
    
private:
    Command parseCommand(string command) {
        if (command == "Enter") return ENTER;
        if (command == "Leave") return LEAVE;
        if (command == "Change") return CHANGE;
        return INVALID;
    }
    
    map<string, string> users;
    vector<Event> events;
};

vector<string> solution(vector<string> record) {
    ChatRoom room;
    
    for (auto event: record) room.parse(event);
    
    return room.getLogs();
}