#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool util(vector<int>& visited, vector<vector<int>> graph, int node, int t){
        if (visited[node] == 0) {
            if (t == 0)
                t = 1;
            visited[node] = t;
            for (int i : graph[node]){
                if (!util(visited, graph, i, -t))
                    return false;
            }
        }
        
        return visited[node]==t; // not else if
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++){
            if (!util(visited, graph, i, visited[i]))
                return false;
        }

        return true;
    }
};



int main(){
    //vector<vector<int>> a{{1,3}, {0,2}, {1,3}, {0, 2}};
    vector<vector<int>> a{{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    Solution s;
    cout << s.isBipartite(a) << endl;

    return 0;
}
