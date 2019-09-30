#include <iostream>
using namespace std;


class Solution {
public:
    string defangIPaddr(string address) {
        string r = "";
        for (char& c : address){
            if (c != '.')
                r += c;
            else 
                r += "[.]";
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
    cout << s.defangIPaddr(str) << endl;

    return 0;
}
