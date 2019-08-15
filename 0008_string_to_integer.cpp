#include <iostream>
using namespace std;

/*
class Solution {
public:
    int myAtoi(string str) {
        if ()
    }
};
*/


int main(int argc, char** argv){
    if (argc < 2){
        cout << "Specify string!" << endl;
        exit(1);
    }
    string s = argv[1];
    cout << *(s.begin()+1) << endl;

    return 0;
}
