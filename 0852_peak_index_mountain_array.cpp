#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i = 1;
        while (A[i] < A[i+1]) i++;

        return i;
    }
};



int main(){
    vector<int> nums{0,1,0};
    Solution s;
    cout << s.peakIndexInMountainArray(nums) << endl;

    return 0;
}
