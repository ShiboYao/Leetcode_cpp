#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0')
            return "0";
        if (num1.size() < num2.size())
            swap(num1, num2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int m = num1.size(), n = num2.size();
        string r;
        int carry = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j <= min(i, n-1); j++)
                carry += (num1[i-j]-'0') * (num2[j]-'0');
            r += carry%10 + '0';
            carry /= 10;
        }
        for (int i = 1; i < m; i++){
            for (int j = i; j < n; j++)
                carry += (num1[m-1+i-j]-'0') * (num2[j] - '0');
            r += carry%10 + '0';
            carry /= 10;
        }
        while (carry){
            r += carry%10 + '0';
            carry /= 10;
        }
        while (r.back() == '0')
            r.pop_back();
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
    string num = s.multiply(num1, num2);
    cout << num << endl;

    return 0;
}

