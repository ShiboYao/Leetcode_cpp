#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> r;
        deque<int> q;
        for (int i = 0; i < n; i++){
            while (!q.empty() && q.front() <= i-k)
                q.pop_front();
            while (!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
            if (i >= k-1)
                r.push_back(nums[q.front()]);
        }

        return r;
    }
};



int main(){
    vector<int> a{1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution s;
    vector<int> r = s.maxSlidingWindow(a, k);
    for (int i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}
