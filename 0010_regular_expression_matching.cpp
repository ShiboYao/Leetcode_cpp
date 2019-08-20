#include <iostream>
using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
        if (p[1] != '*') {
            if (s[0] == p[0] || p[0] == '.' && s[0] != '\0')
                return isMatch(s.substr(1), p.substr(1));
            else
                return false;
        }
        else {
            if (isMatch(s, p.substr(2)))
                return true;
            int index = 0;
            while (index < s.size() && (s[index] == p[0] || p[0] == '.')){
                index++;
                if (isMatch(s.substr(index), p.substr(2)))
                    return true;
            }
        }

        return false;
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "Specify two strings" << endl;
        exit(1);
    }
    Solution s;
    cout << s.isMatch(argv[1], argv[2]) << endl;

    return 0;
}
