#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        string a;
        for (int i = 0; i < s.size(); i++){
            if (a.back()=='(' && s[i]==')' || a.back()=='[' && s[i]==']' || a.back()=='{' && s[i]=='}')
                a.pop_back();
            else
                a.push_back(s[i]);
        }

        return a.empty();
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "Specify string" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.isValid(str) << endl;

    return 0;
}

