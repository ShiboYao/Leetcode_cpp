#include <iostream>
#include <vector>
using namespace std;


class NumArray {
public:
    vector<int> a;
    int n = 0;
    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n){
            a = vector<int>(n+1);
            for (int i = 0; i < n; i++)
                a[i+1] = a[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (n == 0)
            return 0;
        return a[j+1]-a[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */



int main(){
    vector<int> a{-2,0,3,-5,2,-1};
    NumArray* obj = new NumArray(a);
    cout << obj->sumRange(2,5) << endl;

    return 0;
}
