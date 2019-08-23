#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        unordered_map<int, int> mp;
        for (int& i : nums1)
            mp[i]++;
        for (int& j : nums2){
            if (mp[j] > 0){
                a.push_back(j);
                mp[j]--;
            }
        }

        return a;
    }
};



int main(){
    vector<int> a{4,9,5};
    vector<int> b{9,4,9,8,4};
    Solution s;
    vector<int> c = s.intersect(a, b);
    for (int& i : c)
        cout << i << " ";
    cout << endl;

    return 0;
}
