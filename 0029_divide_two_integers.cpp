#include <iostream>
#include <climits>
using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == INT_MIN) return 1;
        if (dividend != INT_MIN && divisor == INT_MIN) return 0;
        if (dividend == INT_MIN){
            if (divisor > 0)
                return divide(INT_MIN + divisor, divisor) - 1;
            else
                return divide(INT_MIN - divisor, divisor) + 1;
        }
        int d = abs(dividend), v = abs(divisor), res = 0;
        for (int i = 31; i >= 0; i--){
            if (d >> i >= v){
                res += 1 << i;
                d -= v << i;
            }
        }

        return (dividend<0) ^ (divisor<0) ? -res : res;
    }
};



int main(){
    Solution s;
    cout << s.divide(7, -3) << endl;

    return 0;
}
