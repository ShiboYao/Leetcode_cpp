#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> r;
        int i = 0, j = numbers.size()-1;
        while (i <= j){
            int sum = numbers[i] + numbers[j];
            if (sum == target){
                r.push_back(i+1);
                r.push_back(j+1);
                break;
            }
            else if (sum < target)
                i++;
            else 
                j--;
        }

        return r;
    }
};


int main(){
    vector<int> a{2,7,11,15};
    int target = 9;
    Solution s;
    vector<int> r = s.twoSum(a, target);
    cout << r[0] << r[1] << endl;

    return 0;
}
