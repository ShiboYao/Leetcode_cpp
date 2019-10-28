#include <iostream>
using namespace std;


class Solution {
public:
    string toLowerCase(string str) {
        string r = "";
        for (char& c : str)
            r += tolower(c);

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
    cout << s.toLowerCase(str) << endl;

    return 0;
}
