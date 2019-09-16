#include <iostream>
using namespace std;


class Solution {
public:
    bool util(string& s, string& t, int i, int j, int count){
        if (count > 1)
            return false;
        if (i == s.size() && j == t.size())
            return count > 0;
        if (s[i] == t[j])
            return util(s, t, i+1, j+1, count);
        else
            return util(s,t,i+1,j,count+1) || util(s,t,i,j+1,count+1) || util(s,t,i+1,j+1,count+1);
    }

    bool isOneEditDistance(string s, string t) {
        return util(s,t,0,0,0);
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "Specify two strs" << endl;
        exit(1);
    }
    string s1 = argv[1], s2 = argv[2];
    Solution s;
    cout << s.isOneEditDistance(s1, s2) << endl;

    return 0;
}
