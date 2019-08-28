#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, sum = 0;
        for (int i = 1; i < prices.size(); i++){
            int diff = prices[i] - prices[i-1];
            if (sum > 0)
                sum += diff;
            else
                sum = diff;
            profit = max(profit, sum);
        }

        return profit;
    }
};



int main(){
    vector<int> a{7,1,5,3,6,4};
    Solution s;
    cout << s.maxProfit(a) << endl;

    return 0;
}
