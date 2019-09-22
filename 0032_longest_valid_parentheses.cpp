#include <iostream>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        int i = 0, j = 0, maxi = 0, n = s.size();
        int l = 0, t = 0;
        while (i < n){
            if (s[i++] == '(') l++;
            else l--;
            if (l == 0){
                t += i-j;
                maxi = max(maxi, t);
                j = i;
            }
            else if (l < 0){
                t = 0;
                j = i;
                l = 0;
            }
        }
        i = n-1, j = n-1, t = 0, l = 0;
        while (i >= 0){
            if (s[i--] == ')') l--;
            else l++;
            if (l == 0){
                t += j-i;
                maxi = max(maxi, t);
                j = i;
            }
            else if (l > 0){
                t = 0;
                j = i;
                l = 0;
            }
        }


        return maxi;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.longestValidParentheses(str) << endl;

    return 0;
}
