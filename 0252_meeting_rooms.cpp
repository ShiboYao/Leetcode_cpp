#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n < 2)
            return true;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        while (i < n-1){
            if (intervals[i][1] > intervals[i+1][0])
                return false;
            i++;
        }

        return true;
    }
};



int main(){
    vector<vector<int>> a{{0,30}, {5,10}, {15,20}};
    Solution s;
    cout << s.canAttendMeetings(a) << endl;

    return 0;
}
