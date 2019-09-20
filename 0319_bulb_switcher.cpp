#include <iostream>
#include <cmath>
using namespace std;


class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify n" << endl;
        exit(1);
    }
    Solution s;
    cout << s.bulbSwitch(argv[1][0]-'0') << endl;

    return 0;
}
