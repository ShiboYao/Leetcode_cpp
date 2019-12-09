#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int bs(vector<int>& nums, int i, int j, int t){
        int low = i, high = j, mid;
        while (low <= high){
            mid = (low+high)/2;
            if (nums[mid] == t)
                return mid;
            else if (nums[mid] < t)
                low = mid+1;
            else
                high = mid-1;
        }

        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, n = numbers.size()-1;
        vector<int> r;
        while (i < n){
            int t = target - numbers[i];
            int p = bs(numbers, i+1, n, t);
            if (p > 0) {
                r.push_back(i+1);
                r.push_back(p+1);
                break;
            }
            i++;
        }

        return r;
    }
};



int main(){
    //vector<int> a{2,7,11,15};
    vector<int> a{5,25,75};
    int t = 100;
    Solution s;
    vector<int> r = s.twoSum(a, t);
    cout << r[0] << " " << r[1] << endl;

    return 0;
}
