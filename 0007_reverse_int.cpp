#include <iostream>
#include <climits>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0;

        bool minus = false;
        if (x < 0){
            minus = true;
            x = -x;
        }
        unsigned r = 0;
        int lim = INT_MAX/10;
        while (x){
            if (r > lim)
                return 0;
            r *= 10;
            r += x%10;
            x /= 10;
        }
        if (minus && r > INT_MAX)
            return 0;
        if (!minus && r > INT_MAX)
            return 0;

        return minus?-(signed int)r:r;
    }
};



int main(){
    int a = 1534236469;
    Solution s;
    int r = s.reverse(a);
    cout << r << endl;

    return 0;
}
