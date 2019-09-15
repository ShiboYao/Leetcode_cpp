#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool util(unordered_map<char, unordered_set<char>>& mp, unordered_map<char, bool>& visited, char node, unordered_set<char> set, string& r){
        if (set.find(node) != set.end())
            return false;
        if (!visited[node]){
            set.insert(node);
            visited[node] = true;
            for (char c : mp[node]){
                if (!util(mp, visited, c, set, r))
                    return false;
            }
            r += node;
        }

        return true;
    }


    string alienOrder(vector<string>& words) {
        int n = words.size();
        if (n == 1)
            return words[0];
        unordered_map<char, unordered_set<char>> mp;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < words[i].size(); j++)
                mp.insert({words[i][j], unordered_set<char>{}});
        }
        for (int i = 1; i < n; i++){
            int a = words[i-1].size(), b = words[i].size();
            for (int j = 0; j < min(a, b); j++){
                if (words[i-1][j] == words[i][j])
                    continue;
                if (j == min(a, b) && a > b)
                     return "";
                mp[words[i][j]].insert(words[i-1][j]);
                break;
            }
        }
        string r = "";
        unordered_map<char, bool> visited;
        for (auto& i : mp){
            if (!visited[i.first]){
                unordered_set<char> set;
                if (!util(mp, visited, i.first, set, r))
                    return "";
            }
        }
       
        return r;
    }
};



int main(){
    //vector<string> a{"wrt", "wrf", "er", "ett", "rftt"};
    //vector<string> a{"z", "x", "z"};
    //vector<string> a{"a", "a"};
    //vector<string> a{"bsusz","rhn","gfbrwec","kuw","qvpxbexnhx","gnp","laxutz","qzxccww"};
    vector<string> a{"a", "b", "ca", "cc"};
    Solution s;
    cout << s.alienOrder(a) << endl;

    return 0;
}
