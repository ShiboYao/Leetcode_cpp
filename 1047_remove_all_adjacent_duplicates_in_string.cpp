#include <iostream>
using namespace std;


class Solution {
public:
    string util(string& s, int i){
        int j = i, n = s.size()-1;
        if (n < 1) return s;
        while (j < n && s[j] != s[j+1])
            j++;
        if (j == n) return s;
        string t = s.substr(0,j) + s.substr(j+2,n-j-1);
        
        return util(t, max(0,j-1));
    }

    string removeDuplicates(string S) {
        return util(S, 0);
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.removeDuplicates(str) << endl;

    return 0;
}
