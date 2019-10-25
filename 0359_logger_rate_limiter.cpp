#include <iostream>
#include <unordered_map>
using namespace std;


class Logger {
unordered_map<string,int> mp;

public:
    /** Initialize your data structure here. */
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (mp.find(message) == mp.end() || mp[message] + 10 <= timestamp){
            mp[message] = timestamp;
            return true;
        }

        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */



 int main(){
     Logger* obj = new Logger();
     cout << obj->shouldPrintMessage(1,"foo") << endl;
     cout << obj->shouldPrintMessage(2,"bar") << endl;
     cout << obj->shouldPrintMessage(3,"foo") << endl;
     cout << obj->shouldPrintMessage(11,"foo") << endl;

     return 0;
 }
