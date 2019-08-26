#include <iostream>
#include <vector>
using namespace std;


class Solution {
private:
    int partition(vector<int>& nums, int low, int high){
        int x = nums[high];
        int i = low, j = low;
        while (j < high){
            if (nums[j] >= x)
                swap(nums[i++], nums[j]);
            j++;
        }
        swap(nums[i], nums[high]);

        return i;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        k--;
        int low = 0, high = nums.size()-1;
        while (1){
            int p = partition(nums, low, high);
            if (p == k)
                return nums[p];
            else if (p > k)
                high = p-1;
            else 
                low = p+1;
        }
    }
};



int main(){
    vector<int> a{3,2,3,1,2,4,5,5,6};
    int k = 4;
    Solution s;
    cout << s.findKthLargest(a, k) << endl;

    return 0;
}
