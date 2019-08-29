#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for (int i = 0; i < intervals.size(); i++){
            mp[intervals[i][0]]++;
            mp[intervals[i][1]]--;
        }
        int count = 0, maxi = 0;
        for (auto& it : mp){
            count += it.second;
            maxi = max(maxi, count);
        }

        return maxi;
    }
};



int main(){
    vector<vector<int>> a{{7,10}, {2,4}};
    Solution s;
    cout << s.minMeetingRooms(a) << endl;

    return 0;
}
