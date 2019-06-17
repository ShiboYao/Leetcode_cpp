#include <iostream>
#include <vector>
using namespace std;


class Solution {
public: 
    int removeDuplicates(vector<int>& nums){
        if (nums.empty())
            return 0;

        int index = 0;
        for (int i = 1; i < nums.size(); i++){
            if (nums[index] != nums[i])
                nums[++index] = nums[i];
        }

        return index+1;
    }
};


int main(){
    vector<int> a{1,2,2,3,4,5};
    Solution s;
    cout << s.removeDuplicates(a) << endl;

    return 1;
}
