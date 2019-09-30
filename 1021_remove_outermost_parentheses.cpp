#include <iostream>
using namespace std;


class Solution {
public:
    string removeOuterParentheses(string S) {
        int l = 0;
        string r = "";
        for (int i = 0; i < S.size(); i++){
            if (l == 0)
                l++;
            else if (l == 1 && S[i] == ')')
                l--;
            else {
                if (S[i] == '(') l++;
                else l--;
                r += S[i];
            }
        }

        return r;    
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.removeOuterParentheses(str) << endl;

    return 0;
}
