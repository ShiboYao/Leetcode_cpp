#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool isStrobogrammatic(string num) {
        vector<char> mp{'0','1','i','a','b','e','9','c','8','6'};
        int i = 0, j = num.size()-1;
        while (i <= j){ 
            if (mp[num[i++]-'0'] != num[j--])
                return false;
        }

        return true;
    }   
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify num str" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.isStrobogrammatic(str) << endl;

    return 0;
}
