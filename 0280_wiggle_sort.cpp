#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return;
        sort(nums.begin(), nums.end());
        int i = 2;
        while (i < n){
            swap(nums[i-1], nums[i]);
            i += 2;
        }
    }
};



int main(){
    vector<int> a{3,5,2,1,6,4};
    Solution s;
    s.wiggleSort(a);
    for (int i : a)
        cout << i << " " ;
    cout << endl;
     
    return 0;
}
