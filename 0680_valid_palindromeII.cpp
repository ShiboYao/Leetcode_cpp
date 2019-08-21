#include <iostream>
using namespace std;


class Solution {
private:
    bool valid(string s, int i, int j){
        while (i < j){
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
public:
    bool validPalindrome(string s) {
        if (s.size() < 3)
            return true;
        int i = 0, j = s.size()-1;
        while (i < j && s[i] == s[j]){
            i++;
            j--;
        }
        if (i >= j)
            return true;
        
        return (valid(s, i+1, j) || valid(s, i, j-1));
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "Specify a str" << endl;
        exit(1);
    }
    Solution s;
    string str = argv[1];
    cout << s.validPalindrome(str) << endl;

    return 0;
}
