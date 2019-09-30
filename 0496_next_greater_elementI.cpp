#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> stack;
        unordered_map<int, int> mp;
        for (int& i : nums2){
            while (!stack.empty() && stack.back() < i){
                mp[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        vector<int> r(nums1.size());
        for (int j = 0; j < nums1.size(); j++){
            if (mp.find(nums1[j]) == mp.end())
                r[j] = -1;
            else
                r[j] = mp[nums1[j]];
        }

        return r;
    }
};



int main(){
    vector<int> a{4,1,2}, b{1,3,4,2};
    Solution s;
    vector<int> r = s.nextGreaterElement(a,b);
    for (int i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}
