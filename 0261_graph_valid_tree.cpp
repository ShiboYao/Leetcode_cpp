#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        if (m != n-1) return false;
        vector<int> nodes(n,0);
        for (int i = 0; i < n; i++)
            nodes[i] = i;
        for (int i = 0; i < m; i++){
            int a = edges[i][0], b = edges[i][1];
            while (nodes[a] != a) a = nodes[a];
            while (nodes[b] != b) b = nodes[b];
            if (nodes[a] == nodes[b])
                return false;
            nodes[a] = b;
        }

        return true;        
    }
};



int main(){
    //vector<vector<int>> a{{0,1},{0,2},{0,3},{1,4}};
    //vector<vector<int>> a{{0,1},{1,2},{2,3},{1,3},{1,4}};
    //vector<vector<int>> a{{0,1},{0,2},{2,3},{2,4}};
    vector<vector<int>> a{{0,1},{2,3},{1,2}};
    int n = 4;
    Solution s;
    cout << s.validTree(n, a) << endl;

    return 0;
}
