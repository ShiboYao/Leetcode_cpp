#include <iostream>
using namespace std;


class Solution {
public:
    bool checkRecord(string s) {
        char pre = 'Q', prepre = 'Q';
        int count = 0;
        for (char& c : s){
            if (c == 'A') count++;
            if (count > 1) return false;
            if (c == 'L' && pre == 'L' && prepre == 'L') return false;
            prepre = pre;
            pre = c;
        }

        return true;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.checkRecord(str) << endl;

    return 0;
}
