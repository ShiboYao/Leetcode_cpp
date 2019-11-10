#include <iostream>
using namespace std;


class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        for (char& c : s){
            if (c == '('){
                cmin++;
                cmax++;
            }
            else if (c == ')'){
                cmax--;
                cmin = max(cmin-1,0);
            }
            else if (c == '*'){
                cmax++;
                cmin = max(cmin-1,0);
            }
            if (cmax < 0)
                return false;
        }

        return cmin == 0;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.checkValidString(str) << endl;

    return 0;
}
