#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class comp {
public:
    bool operator()(const pair<int, int> a, const pair<int, int> b){
        return a.second < b.second;
    }
};


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        for (int i = 0; i < points.size(); i++){
            int d = points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push(make_pair(i, d));
            if (pq.size() > K)
                pq.pop();
        }
        vector<vector<int>> r;
        while (K){
            r.push_back(points[pq.top().first]);
            pq.pop();
            K--;
        }
        
        return r;
    }
};



int main(){
    vector<vector<int>> a{{1,3}, {-2,2}};
    int K = 1;
    Solution s;
    vector<vector<int>> r = s.kClosest(a, K);
    for (vector<int>& i : r){
        for (int& j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
