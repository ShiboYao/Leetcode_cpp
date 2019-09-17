#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int find(vector<int>& parent, int i){
        if (parent[i] == i)
            return i;
        parent[i] = find(parent, parent[i]);

        return parent[i];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n,-1);
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++){
            parent[i] = i;
            for (int j = 1; j < accounts[i].size(); j++){
                if (mp.find(accounts[i][j]) != mp.end()){
                    int p1 = find(parent, i); 
                    int p2 = find(parent, mp[accounts[i][j]]);
                    parent[p1] = p2;
                }
                else 
                    mp[accounts[i][j]] = i;
            }
        }

        unordered_map<int, vector<string>> res;
        for (auto& m : mp)//p points to new p, child didn't update
            res[find(parent, m.second)].push_back(m.first);

        vector<vector<string>> r;
        for (auto& m : res){
            vector<string> t{accounts[m.first][0]};
            sort(m.second.begin(), m.second.end());
            t.insert(t.end(), m.second.begin(), m.second.end());
            r.push_back(t);
        }
        //sort(r.begin(), r.end()); //doesn't need sort because of unordered_map

        return r;
    }
};



int main(){
    vector<vector<string>> accounts{{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
    Solution s;
    vector<vector<string>> r = s.accountsMerge(accounts);
    for (vector<string>& i : r){
        for (string& j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
