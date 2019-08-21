#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1, level = 0, lower, water = 0;
        while (left < right){
            if (height[left] < height[right])
                lower = height[left++];
            else
                lower = height[right--];
            level = max(level, lower);
            water = water + level - lower;
        }

        return water;
    }
};



int main(){
    vector<int> a{1,7,8};
    Solution s;
    int r = s.trap(a);
    cout << r << endl;

    return 0;
}
