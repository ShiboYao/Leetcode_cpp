#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void util(vector<string>& r, string s, int open, int close){
        if (!open && !close){
            r.push_back(s);
            return;
        }
        if (open)
            util(r, s+'(', open-1, close);
        if (open < close)
            util(r, s+')', open, close-1);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> r;
        util(r, "", n, n);

        return r;
    }
};



int main(){
    int n = 3;
    Solution s;
    vector<string> r = s.generateParenthesis(n);
    for (string& i : r)
        cout << i << endl;

    return 0;
}
