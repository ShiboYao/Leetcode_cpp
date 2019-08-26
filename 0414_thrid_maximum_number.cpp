#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/*
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int> pq; 
        for (int n : nums)
            pq.push(n);
        int a = pq.top();
        int maxi = a;
        pq.pop();
        int k = 2;
        while (k){
            int b = pq.top();
            pq.pop();
            if (b != a){ 
                k--;
                a = b;
            }
            if (pq.empty())
                break;
        }
        if (k)
            return maxi;

        return a;
    }   
};
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int maxNum = nums[0];
        long secondNum = LONG_MIN;
        long thirdNum = LONG_MIN;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] > maxNum){
                thirdNum = secondNum;
                secondNum = maxNum;
                maxNum = nums[i];
            }
            else if (maxNum > nums[i] && nums[i] > secondNum){
                thirdNum = secondNum;
                secondNum = nums[i];
            }
            else if (secondNum > nums[i] && nums[i] > thirdNum) 
                thirdNum = nums[i];
        }

        return thirdNum == LONG_MIN?maxNum:thirdNum;
    }
};


int main(){
    vector<int> a{2,2,3,1};
    Solution s;
    cout << s.thirdMax(a) << endl;

    return 0;
}
