#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    void util(vector<vector<int>>& rooms, int i, unordered_set<int>& lock){
        if (lock.empty()) return;
        if (lock.find(i) != lock.end()){
            lock.erase(i);
            for (int& j : rooms[i])
                util(rooms, j, lock);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> lock;
        for (int i = 0; i < n; i++)
            lock.insert(i);
        util(rooms, 0, lock);

        return lock.empty();
    }
};



int main(){
    vector<vector<int>> a{{1},{2},{3},{}};
    //vector<vector<int>> a{{1,3},{3,0,1},{2},{0}};
    Solution s;
    cout << s.canVisitAllRooms(a) << endl;

    return 0;
}
