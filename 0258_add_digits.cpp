#include <iostream>
using namespace std;


class Solution {
public:
    int addDigits(int num) {
        return 1+(num-1)%9;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify num" << endl;
        exit(1);
    }
    Solution s;
    cout << s.addDigits(stoi(argv[1])) << endl;

    return 0;
}
