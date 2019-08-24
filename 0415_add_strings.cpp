#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    string addStrings(string num1, string num2) {
        string r;
        int i = num1.size()-1, j = num2.size()-1;
        int carry = 0;
        while (i >= 0 && j >= 0){
            carry += num1[i--]-'0' + num2[j--]-'0';
            r += carry%10 + '0';
            carry /= 10;
        }
        while (i >= 0){
            carry += num1[i--]-'0';
            r += carry%10 + '0';
            carry /= 10;
        }
        while (j >= 0){
            carry += num2[j--]-'0';
            r += carry%10 + '0';
            carry /= 10;
        }
        if (carry)
            r += '1';
        reverse(r.begin(), r.end());

        return r;
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "Specify two num strings" << endl;
        exit(1);
    }
    string num1 = argv[1], num2 = argv[2];
    Solution s;
    string num = s.addStrings(num1, num2);
    cout << num << endl;

    return 0;
}
