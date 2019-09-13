#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        string r;
        reverse(s.begin(), s.end());
        string::iterator i = s.begin();
        while (i != s.end()){
            while (i != s.end() && *i == ' ')
                i++;
            string::iterator j = i;
            while (j != s.end() && *j != ' ')
                j++;
            reverse(i, j);
            i = j;
        }
        i = s.begin();
        while (i != s.end() && *i == ' ')
            i++;
        while (i != s.end()){
            while (i != s.end() && *i != ' ')
                r += *i++;
            while (i != s.end() && *i == ' ')
                i++;
            if (i != s.end())
                r += ' ';
        }

        return r;
    }
};



int main(int argc, char** argv){
    string str = "   hello world!  ";
    Solution s;
    cout << s.reverseWords(str) << endl;

    return 0;
}
