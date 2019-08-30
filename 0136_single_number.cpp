#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); i++)
            num ^= nums[i];

        return num;
    }
};



int main(){
    vector<int> a{2,2,11};
    Solution s;
    cout << s.singleNumber(a) << endl;

    return 0;
}
