#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class comp{
public:
    bool operator()(const pair<int, int> a, const pair<int, int> b){
        return a.first > b.first;
    }
};



class Solution {
public:
    vector<vector<int>> Hsort(vector<vector<int>> a){
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        for (int i = 0; i < a.size(); i++)
            pq.push(make_pair(a[i][0], i));
        vector<vector<int>> r;
        while (pq.size()){
            r.push_back(a[pq.top().second]);
            pq.pop();
        }

        return r;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n < 2)
            return intervals;
        intervals = Hsort(intervals);
        int i = 0, j = 1;
        while (j < n){
            while (j < n && intervals[i][1] < intervals[j][0])
                intervals[++i] = intervals[j++];
            while (j < n && intervals[i][1] >= intervals[j][0] && intervals[i][1] < intervals[j][1])
                intervals[i][1] = intervals[j++][1];
            while (j < n && intervals[i][1] >= intervals[j][0] && intervals[i][1] >= intervals[j][1])
                j++;
        }
        intervals.resize(i+1);

        return intervals;
    }
};



int main(){
    vector<vector<int>> a{{1,4}, {0,4}};
    Solution s;
    vector<vector<int>> r = s.merge(a);
    for (auto i : r)
        cout << i[0] << "-" << i[1] << " ";
    cout << endl;

    return 0;
}
