#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> r;
        if (nums.size() < 3)
            return r;
        sort(nums.begin(), nums.end());
        
        auto i = nums.begin();
        auto last = nums.end();
        while (i < last - 2){
            while (i != nums.begin() && *i == *(i-1) && i < last-2)
                i++;
            auto j = i + 1;
            auto k = last - 1;
            while (j < k){
                int t = *i + *j + *k;
                if (t < 0){
                    j++;
                    while (*j == *(j-1) && j < k)
                        j++;
                }
                else if (t > 0){
                    k--;
                    while (*k == *(k+1) && j < k)
                        k--;
                }
                else {
                    r.push_back({*i,*j,*k});
                    j++;
                    k--;
                    while (*j == *(j-1) && j < k)
                        j++;
                    while (*k == *(k+1) && j < k)
                        k--;
                    if (*k < 0)
                        break;
                }
            }
            i++;
            if (*i > 0)
                break;
        }

        return r;
    }
};



int main(){
    vector<int> a{-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>> r = s.threeSum(a);
    for (vector<int> &v : r){
        for (int &j : v )
            cout << j << " " ;
        cout << endl;
    }

    return 0;
}
