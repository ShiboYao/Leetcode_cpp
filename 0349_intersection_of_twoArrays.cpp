#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        if (nums1.empty() || nums2.empty())
            return a;
        unordered_map<int, bool> mp;
        for (int& i : nums1)
            mp[i] = true;
        unordered_map<int, bool> r;
        for (int& j : nums2){
            if (mp[j])
                r[j] = true;
        }
        for (auto k : r)
            a.push_back(k.first);

        return a;
    }
};



int main(){
    vector<int> a{4,9,5};
    vector<int> b{9,4,9,8,4};
    Solution s;
    vector<int> c = s.intersection(a, b);
    for (int i : c)
        cout << i << " ";
    cout << endl;

    return 0;
}
