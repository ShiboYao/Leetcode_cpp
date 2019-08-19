#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        int carry = 1;
        while (i >= 0){
            if (digits[i] + carry > 9)
                digits[i--] = 0;
            else 
                break;
        }
        if (carry){
            if (i >= 0)
                digits[i]++;
            else
                digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};



int main(){
    vector<int> digits{1,9,9};
    Solution s;
    vector<int> r = s.plusOne(digits);
    for (auto a : r)
        cout << a << ' ';
    cout << endl;

    return 0;
}
