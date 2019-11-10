#include <iostream>
using namespace std;


class Solution {
public:
    int scoreOfParentheses(string S) {
        int r = 0, a = 0, n = S.size();
        for (int i = 0; i < n-1; i++){
            if (S[i] == '('){
                if (S[i+1] == ')')
                    r += 1<<a;
                a++;
            }
            else
                a--;
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
    cout << s.scoreOfParentheses(str) << endl;

    return 0;
}
