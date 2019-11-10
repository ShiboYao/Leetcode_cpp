#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int i = 0, n = bills.size();
        unordered_map<int,int> mp;
        while (i < n){
            if (bills[i] == 5)
                mp[5]++;
            else if (bills[i] == 10){
                if (mp[5] == 0)
                    return false;
                else {
                    mp[5]--;
                    mp[10]++;
                }
            }
            else {
                if (mp[5] == 0 || (mp[10] == 0 && mp[5] < 3))
                    return false;
                else {
                    if (mp[5] > 0 && mp[10] > 0){
                        mp[5]--;
                        mp[10]--;
                    }
                    else 
                        mp[5] -= 3;
                }
            }
            i++;
        }

        return true;
    }
};



int main(){
    vector<int> a{5,5,5,10,20};
    Solution s;
    cout << s.lemonadeChange(a) << endl;

    return 0;
}
