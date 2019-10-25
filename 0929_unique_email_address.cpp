#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;


class Solution {
public:
    string convert(string& s){
        int i = 0, n = s.size();
        while (s[i] != '.' && s[i] != '+' && s[i] != '@')
            i++;
        if (s[i] == '@')
            return s;
        else if (s[i] == '.'){
            string t = s.substr(i+1, n-i-1);
            return s.substr(0,i)+convert(t);
        }
        else {
            int j = i+1;
            while (s[j] != '@')
                j++;
            string t = s.substr(j, n-j);
            return s.substr(0,i)+t;
        }
    }

    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (string& email : emails){
            string str = convert(email);
            s.insert(str);
        }

        return s.size();
    }
};



int main(){
    vector<string> emails{"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    Solution s;
    cout << s.numUniqueEmails(emails) << endl;

    return 0;
}
