#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, n = s.size();
        while (i < n){
            while (i < n && s[i] != ' ')
                i++;
            reverse(s.begin()+j, s.begin()+i);
            while (i < n && s[i] == ' ')
                i++;
            j = i;
        }

        return s;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    Solution s;
    cout << s.reverseWords(argv[1]) << endl;

    return 0;
}
