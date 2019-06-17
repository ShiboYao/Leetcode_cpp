#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (!nums.size())
            return;

        int i = 0, j = 0;
        while (j < nums.size()){
            while (j < nums.size() && nums[j] == 0)
                j++;
            while (j < nums.size() && nums[j] != 0)
                nums[i++] = nums[j++];
        }
        while (i < j)
            nums[i++] = 0;
    }
};
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (!nums.size())
            return;
        int index = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i])
                nums[index++] = nums[i];
        }
        while (index < nums.size())
            nums[index++] = 0;
    }
};


int main(){
    vector<int> a{1,3,6,8,0,0,7,9,0,5,3,3,6,8,0};
    Solution s;
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << '\n';
    s.moveZeroes(a);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << '\n';

    return 0;
}
