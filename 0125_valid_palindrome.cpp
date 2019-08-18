#include <iostream>
#include <cctype>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty() || s.size() == 1)
            return true;
        int i = 0, j = s.size()-1;
        int move = 0;
        while (i < j){
            while (i < j && !isalnum(s[i])){
                i++;
                move++;
            }
            while (i < j && !isalnum(s[j])){
                j--;
                move++;
            }
            while (i < j && tolower(s[i]) == tolower(s[j])){
                i++;
                j--;
                move++;
            }
            if (move == 0)
                break;
            move = 0;
        }

        return i<j?false:true;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "Specify string!" << endl;
        exit(1);
    }

    string str = argv[1];
    Solution s;
    bool r = s.isPalindrome(str);
    cout << r << endl;

    return 0;
}
