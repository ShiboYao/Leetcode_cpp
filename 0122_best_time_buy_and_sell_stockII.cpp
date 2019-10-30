#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0, n = prices.size();
        for (int i = 1; i < n; i++)
            sum += max(0,prices[i]-prices[i-1]);

        return sum;
    }
};



int main(){
    vector<int> a{7,1,5,3,6,4};
    Solution s;
    cout << s.maxProfit(a) << endl;

    return 0;
}
