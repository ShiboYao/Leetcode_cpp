#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int maxi = 0, high;
        while (i < j){
            high = min(height[i], height[j]);
            maxi = max(maxi, (j-i)*high);
            while (i < j && height[i] <= high)
                i++;
            while (i < j && height[j] <= high)
                j--;
        }

        return maxi;
    }
};



int main(){
    vector<int> a{1,8,6,2,5,4,8,3,7};
    //vector<int> a{1,1};
    Solution s;
    cout << s.maxArea(a) << endl;

    return 0;
}
