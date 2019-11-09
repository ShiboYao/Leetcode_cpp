#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<pair<int,int>>> dis(2001);
        int m = workers.size(), n = bikes.size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                int d = abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1]);
                dis[d].push_back({i,j});
            }
        }
        vector<int> res(m,-1);
        vector<bool> bikeUsed(n,false);
        for (int d = 0; d <= 2000; d++){
            for (int k = 0; k < dis[d].size(); k++){
                if (res[dis[d][k].first] == -1 && !bikeUsed[dis[d][k].second]){
                    bikeUsed[dis[d][k].second] = true;
                    res[dis[d][k].first] = dis[d][k].second;
                }
            }
        }

        return res;
    }
};



int main(){
    vector<vector<int>> workers{{0,0},{2,1}}, bikes{{1,2},{3,3}};
    Solution s;
    vector<int> r = s.assignBikes(workers, bikes);
    for (int i : r)
        cout << i << " ";
    cout << endl;;

    return 0;
}
