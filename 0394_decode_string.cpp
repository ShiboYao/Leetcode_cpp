#include <iostream>
#include <cctype>
using namespace std;


class Solution {
public:
    string util(string& s, int i, int n){
        if (i >= n) return "";
        
        int j = i;
        while (j < n && isalpha(s[j]))
            j++;
        if (j > i)
            return s.substr(i,j-i) + util(s, j, n);
        
        while (isdigit(s[j]))
            j++;
        int num = stoi(s.substr(i,j-i));
        int l = 1;
        i = ++j;
        while (l > 0){
            if (s[j] == '[') l++;
            else if (s[j] == ']') l--;
            j++;
        }
        string str = util(s, i, j-1);
        string str_ = "";
        while (num){
            str_ += str;
            num--;
        }

        return str_ + util(s, j, n);
    }

    string decodeString(string s) {
        int i = 0, n = s.size();

        return util(s, i, n);
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    Solution s;
    cout << s.decodeString(argv[1]) << endl;

    return 0;
}
