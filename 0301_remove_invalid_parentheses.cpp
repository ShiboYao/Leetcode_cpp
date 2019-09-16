#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void util(vector<string>& re, string cur, int l, int r, int& maxi, int i, string& s){
        if (l < r)
            return;
        if (i == s.size()){
            if (l == maxi && r == maxi)
                re.push_back(cur);
            return;
        }
        if (s[i] == ')'){
            if (cur.empty() || cur.back() != ')')
                util(re, cur,l,r,maxi,i+1,s);
            util(re, cur+")",l,r+1,maxi,i+1,s);
        }
        else if (s[i] == '('){
            if (cur.empty() || cur.back() != '(')
                util(re, cur,l,r,maxi,i+1,s);
            util(re, cur+"(",l+1,r,maxi,i+1,s);
        }
        else 
            util(re, cur+s[i],l,r,maxi,i+1,s);
    }


    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0, maxi = 0;
        for (char c : s){
            if (c == '(')
                l++;
            else if (c == ')'){
                if (l > 0){
                    l--;
                    maxi++;
                }
            }
        }
        vector<string> re;
        string cur = "";
        util(re, cur, 0, 0, maxi, 0, s);

        return re;
    }
};



int main(){
    //string str = "()())()";
    //string str = ")(";
    string str = "(()";
    Solution s;
    vector<string> re = s.removeInvalidParentheses(str);
    for (string& i : re)
        cout << i << endl;

    return 0;
}
