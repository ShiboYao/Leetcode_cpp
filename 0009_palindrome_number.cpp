#include <iostream>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int y = x;
        int digit = 0;
        while (y){
            y /= 10;
            digit++;
        }
        
        int half_digit = digit/2;
        int r = 0;
        while (half_digit){
            r = r*10 + x%10;
            x /= 10;
            half_digit--;
        }
        if (digit%2)
            r = r*10 + x%10;

        return x==r;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify an integer" << endl;
        exit(1);
    }
    int a = stoi(argv[1]);
    Solution s;
    cout << s.isPalindrome(a) << endl;

    return 0;
}
