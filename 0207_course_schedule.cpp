#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool util(vector<vector<int>>& adj, int node, vector<bool>& visited, vector<bool>& stack){
        if (!visited[node]){
            visited[node] = true;
            stack[node] = true;
            for (int& i : adj[node]){
                if (stack[i]) return true;
                if (!visited[i] && util(adj, i, visited, stack))
                    return true;
            }
            stack[node] = false;
        }

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> stack(numCourses, false);
        vector<vector<int>> adj(numCourses);
        for (vector<int>& i : prerequisites)
            adj[i[0]].push_back(i[1]);
        for (int i = 0; i < numCourses; i++){
            if (!visited[i] && util(adj, i, visited, stack))
                return false;
        }

        return true;
    }
};



int main(){
    vector<vector<int>> a{{1,0},{0,1}};
    //vector<vector<int>> a{{0,1}};
    int n = 2;
    Solution s;
    cout << s.canFinish(n, a) << endl;

    return 0;
}
