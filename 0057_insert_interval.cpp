#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool overlap(vector<int>& a, vector<int>& b){
        if (a[0] > b[1] || a[1] < b[0]) return false;
        return true;
    }


    vector<int> merge(vector<int>& a, vector<int>& b){
        return vector<int>{min(a[0],b[0]), max(a[1],b[1])};
    }


    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0, n = intervals.size();
        while (i < n && intervals[i][0] < newInterval[0])
            i++;
        intervals.insert(intervals.begin()+i, newInterval);
        i = max(0,i-1);
        int j = i+1;
        while (j <= n){
            if (overlap(intervals[i],intervals[j]))
                intervals[i] = merge(intervals[i],intervals[j++]);
            else
                intervals[++i] = intervals[j++];
        }
        intervals.resize(i+1);

        return intervals;
    }
};



int main(){
    vector<vector<int>> a{{1,3},{6,9}};
    vector<int> b{2,5};
    //vector<vector<int>> a{{1,2},{3,5},{6,7},{8,10},{12,16}};
    //vector<int> b{4,8};
    //vector<vector<int>> a{{0,5},{9,12}};
    //vector<int> b{7,16};
    Solution s;
    vector<vector<int>> c = s.insert(a,b);
    for (vector<int>& i : c)
        cout << i[0] << "-" << i[1] << endl;

    return 0;
}
