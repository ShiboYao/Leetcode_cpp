#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    string convertToTitle(int n) {
        string r = "";
        while (n){
            r += 'A' + --n%26;
            n /= 26;
        }
        reverse(r.begin(), r.end());

        return r;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    int n = stoi(argv[1]);
    Solution s;
    cout << s.convertToTitle(n) << endl;

    return 0;
}
