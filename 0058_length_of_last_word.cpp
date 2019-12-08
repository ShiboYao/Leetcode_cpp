#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = s.size()-1;
        while (j >= 0 && s[j] == ' ')
            j--;
        if (j < 0) return 0;
        int i = j;
        while (i >= 0 && s[i] != ' ')
            i--;

        return j-i;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.lengthOfLastWord(str) << endl;

    return 0;
}
