#include <iostream>
using namespace std;


class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size()-1, count = 0;
        long d = 1;
        while (n >= 0){
            count += (s[n]-'A'+1)*d;
            d *= 26;
            n--;
        }

        return count;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.titleToNumber(str) << endl;

    return 0;
}
